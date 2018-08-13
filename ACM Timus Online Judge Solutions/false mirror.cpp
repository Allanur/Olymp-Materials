# include <stdio.h>
# include <string.h>

# define INF 999999999
# define min1(x,y) ( x<y ? x : y )

int n,k=1;

int arr[25];

int vis[1100009];

int qu[1100009];

bool vis1[1100009];

	int add(int x)
	{
		int sum=0,q=n-1;
		
		while(x>0)
		{
			if(x%2 == 1) sum+=arr[q];
			
			q--;x/=2;
		}
		
		return sum;
	}

	int find(int x, int y)
	{
		int sum=0,de[25],q=0;
		
		memset(de,0,sizeof(de));
		
		while(x>0) {de[q]=x%2,q++,x/=2;}
		
		int e1=y-1,e2=y,e3=y+1;
		
		if(e3 == n) e3=0;
		if(e1 == -1) e1=n-1;
		
		de[e1]=0,de[e2]=0;de[e3]=0;
		
		int q1=1;
		
		for	(int i=0;i<n;i++) sum+=q1*de[i],q1*=2;
		
		return sum;
	}

	int bfs(int x)
	{
		int i=0,j=1;
		
		qu[0]=x;
		vis1[x]=1;
		while(i<j)
		{
			for	(int o=1;o<=n;o++)
			{
				int h=find(qu[i],n-o);
				int h1=add(h);
				
				vis[h]=min1(h1+vis[qu[i]],vis[h]);
				
				if(vis1[h] == 0) vis1[h]=1,qu[j]=h,j++;
			}
			
			i++;
		}
		
		return vis[0];
	}  

int main()
{
	scanf("%d",&n);
	
	for	(int i=0;i<n;i++) scanf("%d",&arr[i]);
	
	k=k<<n;k--;
	
	for	(int i=0;i<k;i++) vis[i]=INF;
	vis[k]=0;
	
	int ans=bfs(k);
	
	printf("%d",ans);
}
