#include<stdio.h>
#include<string.h>
int main()
{
	int T,TT;
	long long i,j,n,L,B,cnt[3],rnd;
	bool b[3];
	scanf("%d",&TT);
	for(T=1;T<=TT;T++)
	{
		scanf("%lld",&n);
		cnt[0]=cnt[1]=cnt[2]=0;
		b[0]=b[1]=b[2]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&L,&B);
			if(B%3==0)cnt[0]+=(L-1)*(B-1);
			if(B%3==1)cnt[1]+=(L-1)*(B-1);
			if(B%3==2)
			{
				cnt[2]+=(L-1+1)/2*(B-1);
				cnt[1]+=(L-1)/2*(B-1);
			}
		}
		
		printf("Case %d: ",T);
		
		if(cnt[1]==0&&cnt[2]==0)
		{
			if(cnt[0]==0)
			{
				printf("Draw\n");
			}
			else
			{
				printf("J\n");
			}
		}
		
		if(cnt[1]==0&&cnt[2]!=0)
		{
			if(cnt[2]<=2)
			{
				printf("Draw\n");
			}
			else
				if(cnt[0]%2==1)
				{
					printf("M\n");
				}
				else
				{
					printf("J\n");
				}
		}
		
		if(cnt[1]!=0&&cnt[2]==0)
		{
			if(cnt[1]<=2)
			{
				printf("Draw\n");
			}
			else
				if(cnt[0]%2==1)
				{
					printf("M\n");
				}
				else
				{
					printf("J\n");
				}
		}
////////////////////////////////////////////////////////////////
		if(cnt[1]!=0&&cnt[2]!=0)
		{
			if(cnt[1]-1>cnt[2]+1)
			{
				rnd=cnt[2]*2+2+cnt[0];
				if(rnd%2==1)
				{
					b[0]=1;
				}
				else
				{
					b[2]=1;
				}
			}
			else
			if(cnt[1]-1==cnt[2]+1||cnt[1]-1==cnt[2])
			{
				b[1]=1;
			}
			else
			{
				rnd=cnt[1]*2-1+cnt[0];
				if(rnd%2==1)
				{
					b[0]=1;
				}
				else
				{
					b[2]=1;
				}
			}
////////////////////////////////////////////////////////////////
			if(cnt[2]-1>cnt[1]+1)
			{
				rnd=cnt[1]*2+2+cnt[0];
				if(rnd%2==1)
				{
					b[0]=1;
				}
				else
				{
					b[2]=1;
				}
			}
			else
			if(cnt[2]-1==cnt[1]+1||cnt[2]-1==cnt[1])
			{
				b[1]=1;
			}
			else
			{
				rnd=cnt[2]*2-1+cnt[0];
				if(rnd%2==1)
				{
					b[0]=1;
				}
				else
				{
					b[2]=1;
				}
			}
			if(b[0])printf("M\n");
			else
			if(b[1])printf("Draw\n");
			else
			printf("J\n");
		}
	}
	return 0;
}

