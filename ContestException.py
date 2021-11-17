
class SourceNotFoundException(Exception):
    def __init__(self):
        pass

    def __str__(self):
        pass

class ContestantNotFoundException(Exception):
    pass

class UnexpectedDirFoundException(Exception):
    pass

class NoSubdirectoryException(Exception):
    pass
