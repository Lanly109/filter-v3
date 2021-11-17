#!/usr/bin/python3

import yaml,os,shutil,time
import argparse
import ContestException
import glob

from os import path
from shutil import copyfile,copy2

def get_yaml_data(yamlFilePath:str):
    '''
    yamlFilePath ： 作为配置文件的.yml的文件地址
    具体的yml参数可参考范例和README
    
    return: py的yaml格式文件
    '''
    try:
        file = open(yamlFilePath, 'r', encoding='utf-8')
    except Exception as e:
        print("Sorry, Cannot open yaml file.")
        raise e
    raw_data = file.read()
    file.close()
    try:
        return yaml.load(raw_data, Loader=yaml.FullLoader)
    except Exception as e:
        print("Sorry, Cannot scanning yaml file.")
        raise e


def checkContestant(contestantDir:str, contestantList:list):
    '''
    contestantDir : 包含所有选手个人文件夹的路径
        比如收集两个选手
        ./NOIP/
            GD-00001
            GD-00002
        那么contestantDir = './NOIP/'
    contestantList : 从csv中读取的报名了的选手考号
        比如['GD-00001','GD-00002']
    
    return :
        报名且正确提交个人文件的选手列表
    '''
    contestantList = set(contestantList)
    contestantExists = set(os.listdir(contestantDir))
    contestantExtra = contestantExists.difference(contestantList)
    contestantLack = contestantList.difference(contestantExists)
    # print("debug check:",contestantList, contestantExists)
    print("Contestant without submissions:",contestantLack)
    print("Contestant should not in this site:",contestantExtra)
    return list(contestantList.intersection(contestantExists))

def getContestantIDfromCSVfile(filePath:str,roomName,skipHead):
    '''
    从csv名单中读取报了名、在某个特定考场的考生ID.
    这个CSV文件的格式限制：
    第一列为考号，第二列为考场，其余列为其他信息。比如
    GD-XXXXX    J1  Junior2 Zhang3
    GD-YYYYY    J2..Junior1.Zhang2
    GD-ZZZZZ    S1..Senior1.Foxing

    filePath:
        csv文件的路径
    roomName:
        试室编号，比如'J1'。当roomName为空字符串('')，表示选取所有试室。
    return:
        报名选手ID的列表
    '''
    try:
        if csvGBK:
            file = open(filePath,'r', encoding="gbk")
        else:
            file = open(filePath,'r', encoding='utf-8')
    except Exception as e:
        print('The contestant csvfile cannot be open.')
        raise e
    
    lis = []
    if skipHead:
        next(file)
    for line in file:
        l = line.strip().split(',')
        if len(l)<2:
            raise Exception()
        if str(l[1]) == str(roomName) or roomName == '':
            lis.append(l[0])
    return lis

def writeSummaryToCSV(submissionDict:dict, logFilePath:str):
    '''
    对每个合法提交的选手ID，记录其正确提交了哪些题目的源文件
    submissionDict:
        选手ID->每个题目是否提交的字典
        比如 GD-0001提交了A，没有提交B，那么
            [Gd-0001] = {'A':True, 'B':False}
    logFilePath:
        log文件路径
    '''
    try:
        logfile = open(logFilePath, 'w')
    except Exception as e:
        print("Cannot create log file.")
        raise e
    for contestant in submissionDict.keys():
        submitProbs = submissionDict[contestant]
        print(contestant,file = logfile,end='')
        for p in submitProbs.keys():
            print(','+(p if submitProbs[p] else ''), file=logfile,end='')
        print(file=logfile)
    

def parsing():
    '''
    py的参数，指定yaml配置文件，默认为当前目录下的config.yml
    '''
    parser = argparse.ArgumentParser()
    parser.add_argument('--taryml',help="The target constant source directory.",default="./config.yml")
    args = parser.parse_args()
    print("The target configuration yml is:",args.taryml)
    return args.taryml

if __name__ == "__main__":
    currentPath = path.abspath(".")
    yamlPath = parsing()
    cfg = get_yaml_data(yamlPath)
    beginTime = cfg['BeginTime']
    endTime = cfg['EndTime']
    csvGBK = cfg['CsvGBK']
    timeerrorlog = cfg['TimeErrorLog']
    beg = time.strptime(beginTime, "%Y-%m-%d %H:%M:%S")
    end = time.strptime(endTime, "%Y-%m-%d %H:%M:%S")
    # 有些试室号全数字会被yaml解析成int，需强制转一下str。
    cfg['RoomName'] = str(cfg['RoomName'])

    contestantPath = path.join(
                        cfg['ContestantPath'],
                        cfg['RoomName']
    )
    contestSite = cfg['ContestSite']
    contestantList = getContestantIDfromCSVfile(
                        path.join(currentPath,cfg['ContestantListFile']),
                        cfg['RoomName'],
                        cfg['SkipHead']
                    )
    probList = cfg['Problems']
    targetPath = cfg['TargetPath']

    #检查选手名单与实际提交选手的差别
    try:
        validContestants= checkContestant(contestantPath, contestantList)
    except Exception as e:
        raise e

    #对于合法选手，检查其每一题下每一个提交文件名是否符合格式
    #符合格式则考虑移动到targetPath下
    contestantSubmission = {}
    if targetPath:
        os.makedirs(targetPath)
    for c in validContestants:
        if targetPath:
            os.makedirs(path.join(targetPath,c))
        submitted = {}
        for prob in probList:
            problemFound = False
            for suf in cfg['ValidSuffix']:
                sourceFile = path.join(c,prob,prob+'.'+suf)
                sourceAbsFile = path.join(contestantPath, sourceFile)
                if os.path.exists(sourceAbsFile):
                    problemFound = True

                    if targetPath is None:
                        continue
                    #如果taretPath非空，那么就移动
                    targetsourceAbsFile = path.join(targetPath,sourceFile)
                    if not path.exists(path.dirname(targetsourceAbsFile)):
                        os.makedirs(path.dirname(targetsourceAbsFile))
                    #copy2 = copyfile + copystat，否则修改时间会被改动。
                    copy2(sourceAbsFile,targetsourceAbsFile)
            submitted[prob]=problemFound
        contestantSubmission[c] = submitted
    writeSummaryToCSV(contestantSubmission,cfg['SummaryFile'])

    #检查修改时间，显示最新的5个
    filesWithMT = []
    checkpath = targetPath if targetPath is not None else contestantPath
    for dirpath, _, filenames in os.walk(checkpath):
        for filename in filenames:
            filepath = path.join(dirpath,filename)
            filesWithMT.append((path.getmtime(filepath),filepath))
    
    print(checkpath, len(filesWithMT))
    filesWithMT = sorted(filesWithMT, key=lambda x: x[0], reverse=True)
    print("Some of the lastest modified files:")
    for i in range(10):
        if i>=len(filesWithMT):
            break
        x = filesWithMT[i]
        print("File:",x[1])
        print("    Last modified:",time.ctime(x[0]))

    print('\nTime Error Detected:')

    with open(timeerrorlog, "w", encoding='gbk') as f:
        for x in filesWithMT:
            tt = time.localtime(x[0])
            if tt >= beg and tt < end:
                continue
            xx = x[1].split('/')
            if not xx[-1].endswith('cpp') and not x[-1].endswith('c') and not x[-1].endswith('pas'):
                continue
            num = xx[-3]
            pro = xx[-1]
            tt = time.strftime('%Y-%m-%d %H:%M:%S', tt)
            f.write(f"{num}的{pro}修改时间为{tt}；\n")
            print(f"{num}的{pro}修改时间为{tt}；")

    print(f"\nSaved in {timeerrorlog}\n")


    del checkpath
    _ = input("Please press any key to break.")
