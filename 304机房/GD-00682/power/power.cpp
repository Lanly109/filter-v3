#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;
long long a[65];
void d(){
	long long sum=1;
	for(long long i=1;i<=32;i++){
		a[i]=sum;
		sum*=2;
	}
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	d();
	long long n;
	scanf("%lld",&n);
	if(n%2==1){
		printf("-1");
		return 0;
	}
	for(long long i=1;i<=32;i++){
		if(n==a[i]){
			printf("%lld",n);
			return 0;
		}
	}
	for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			if(n-a[i]==a[j]){
				printf("%lld %lld",a[j],a[i]);
				return 0;
			}
		}
	}
	for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				if(n-a[i]-a[j]==a[k]){
					printf("%lld %lld %lld",a[k],a[j],a[i]);
					return 0;
				}
			}
		}
	}
	for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					if(n-a[i]-a[j]-a[k]==a[s]){
						printf("%lld %lld %lld %lld",a[s],a[k],a[j],a[i]);
						return 0;
					}
				}
			}
		}
	}
	for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					for(long long q=s+1;q<=32;q++){
						if(n-a[i]-a[j]-a[k]-a[s]==a[q]){
							printf("%lld %lld %lld %lld %lld",a[q],a[s],a[k],a[j],a[i]);
							return 0;
						}
					}
				}
			}
		}
	}
	for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					for(long long q=s+1;q<=32;q++){
						for(long long w=q+1;w<=32;w++){
							if(n-a[i]-a[j]-a[k]-a[s]-a[q]==a[w]){
								printf("%lld %lld %lld %lld %lld %lld",a[w],a[q],a[s],a[k],a[j],a[i]);
								return 0;
							}
						}
					}
				}
			}
		}
	}
	for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					for(long long q=s+1;q<=32;q++){
						for(long long w=q+1;w<=32;w++){
							for(long long b=w+1;b<=32;b++){
								if(n-a[i]-a[j]-a[k]-a[s]-a[q]-a[w]==a[b]){
									printf("%lld %lld %lld %lld %lld %lld %lld",a[b],a[w],a[q],a[s],a[k],a[j],a[i]);
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}
	for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					for(long long q=s+1;q<=32;q++){
						for(long long w=q+1;w<=32;w++){
							for(long long b=w+1;b<=32;b++){
								for(long long c=b+1;c<=32;c++){
									if(n-a[i]-a[j]-a[k]-a[s]-a[q]-a[w]-a[b]==a[c]){
										printf("%lld %lld %lld %lld %lld %lld %lld %lld",a[c],a[b],a[w],a[q],a[s],a[k],a[j],a[i]);
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
		for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					for(long long q=s+1;q<=32;q++){
						for(long long w=q+1;w<=32;w++){
							for(long long b=w+1;b<=32;b++){
								for(long long c=b+1;c<=32;c++){
									for(long long d=c+1;d<=32;d++){
										if(n-a[i]-a[j]-a[k]-a[s]-a[q]-a[w]-a[b]-a[c]==a[d]){
											printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",a[d],a[c],a[b],a[w],a[q],a[s],a[k],a[j],a[i]);
											return 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
			for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					for(long long q=s+1;q<=32;q++){
						for(long long w=q+1;w<=32;w++){
							for(long long b=w+1;b<=32;b++){
								for(long long c=b+1;c<=32;c++){
									for(long long d=c+1;d<=32;d++){
										for(long long e=d+1;e<=32;e++){
											if(n-a[i]-a[j]-a[k]-a[s]-a[q]-a[w]-a[b]-a[c]-a[d]==a[e]){
												printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",a[e],a[d],a[c],a[b],a[w],a[q],a[s],a[k],a[j],a[i]);
												return 0;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					for(long long q=s+1;q<=32;q++){
						for(long long w=q+1;w<=32;w++){
							for(long long b=w+1;b<=32;b++){
								for(long long c=b+1;c<=32;c++){
									for(long long d=c+1;d<=32;d++){
										for(long long e=d+1;e<=32;e++){
											for(long long f=e+1;f<=32;f++){
												if(n-a[i]-a[j]-a[k]-a[s]-a[q]-a[w]-a[b]-a[c]-a[d]-a[e]==a[f]){
													printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",a[f],a[e],a[d],a[c],a[b],a[w],a[q],a[s],a[k],a[j],a[i]);
													return 0;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
		for(long long i=2;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					for(long long q=s+1;q<=32;q++){
						for(long long w=q+1;w<=32;w++){
							for(long long b=w+1;b<=32;b++){
								for(long long c=b+1;c<=32;c++){
									for(long long d=c+1;d<=32;d++){
										for(long long e=d+1;e<=32;e++){
											for(long long f=e+1;f<=32;f++){
												for(long long g=f+1;g<=32;g++){
													if(n-a[i]-a[j]-a[k]-a[s]-a[q]-a[w]-a[b]-a[c]-a[d]-a[e]-a[f]==a[g]){
														printf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",a[g],a[f],a[e],a[d],a[c],a[b],a[w],a[q],a[s],a[k],a[j],a[i]);
														return 0;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(long long i=1;i<=32;i++){
		for(long long j=i+1;j<=32;j++){
			for(long long k=j+1;k<=32;k++){
				for(long long s=k+1;s<=32;s++){
					for(long long q=s+1;q<=32;q++){
						for(long long w=q+1;w<=32;w++){
							for(long long b=w+1;b<=32;b++){
								for(long long c=b+1;c<=32;c++){
									for(long long d=c+1;d<=32;d++){
										for(long long e=d+1;e<=32;e++){
											for(long long f=e+1;f<=32;f++){
												for(long long g=f+1;g<=32;g++){
													for(long long h=g+1;h<=32;h++){
														if(n-a[i]-a[j]-a[k]-a[s]-a[q]-a[w]-a[b]-a[c]-a[d]-a[e]-a[f]-a[g]==a[h]){
															printf("%d %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",a[h],a[g],a[f],a[e],a[d],a[c],a[b],a[w],a[q],a[s],a[k],a[j],a[i]);
															return 0;
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
		return 0;
}
