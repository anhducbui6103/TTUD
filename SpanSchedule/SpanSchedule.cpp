#include<bits/stdc++.h>
using namespace std;

 

typedef struct AdjList
{
    int size; // số lượng đỉnh kề
    int *list; // danh sách các đỉnh kề
} ADJ;

 

int * loadNodeWeighted( int n)
{
    int *weighted = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        cin>>weighted[i];
    return weighted;
}

 

ADJ *loadAdjList(int n, int m)
{
    ADJ * lstAdj = (ADJ *)malloc(n*sizeof(ADJ));
    for(int i=0;i<n;i++)
    {
        lstAdj[i].size=0;
        lstAdj[i].list = (int *)malloc(n*sizeof(int));
    }
    int preId = 0;
    int a,b;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        lstAdj[a-1].list[lstAdj[a-1].size] = b;
        lstAdj[a-1].size++;
    }
    return lstAdj;
}

 

void loadData(int *n, int *m,int **weighted, ADJ **lstAdj )
{
    int n1,m1;
    cin>>n1>>m1;
    *weighted = loadNodeWeighted(n1);
    *lstAdj = loadAdjList(n1,m1);
    *n = n1;
    *m=m1;
}

 

void print(int n, int m, int *weighted, ADJ *lstAdj)
{
    cout<<n<<" "<<m<<endl;
    for(int i=0;i<n;i++) printf("%d ", weighted[i]);
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("id %d size %d ",i+1, lstAdj[i].size);
        for(int j=0;j<lstAdj[i].size;j++){
            printf("%d ", lstAdj[i].list[j]);
            printf("\n");
        }
    }
}
void process(int n, int m, int *weighted, ADJ *lstAdj)
{
    priority_queue<pair<int,int>> nextNodes;
    priority_queue<pair<int,int>> timeline;
    
    // tính bậc các đỉnh
    int *edgeDegree= (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)edgeDegree[i]=0;
    
    // tính bậc
    for(int i=0;i<n;i++)
    {
        int vertex;
        for(int j=0;j<lstAdj[i].size;j++){
            vertex = lstAdj[i].list[j];
            printf("bậc đỉnh %d %d \n",i+1, vertex);
            edgeDegree[vertex-1]++;
        }
    }    
    // đưa vào trong heap
    for(int i=0;i<n;i++)
    {
        printf("%d %d \n",i+1, edgeDegree[i]);
        nextNodes.push({edgeDegree[i]*-1,i});      
    }
    
    int curTime = 0;
    
    do
    {        
        while(!nextNodes.empty())
        {
            // lấy những đỉnh bậc 0 và đưa sang hàng đợi timeline
            pair<int,int> top=nextNodes.top();
            if(top.first==0)
            {
                nextNodes.pop();
                timeline.push({-1*(curTime+weighted[top.second]),top.second});
            }
            else{
                break;
            }        
        }
        // xử lý timeline
        if(!timeline.empty())
        {
            pair<int,int> top=timeline.top();
            timeline.pop();
            //cập nhật lại currTime
            curTime = -1*top.first;
            int vertex = top.second;
            // trừ 1 bậc của các đỉnh xuất phát từ vertex
            // và cập nhật lại hàng đợi về bậc
            for(int i=0;i<lstAdj[vertex].size; i++)
            {
                int j = lstAdj[vertex].list[i]-1;
                edgeDegree[j]--;
                nextNodes.push({edgeDegree[j]*-1,j});  
            }
        }
        else
        {
            break;//kết thúc công việc
        }
    }while(1);
    
    printf("Total time: %d\n",curTime);
    
    free(edgeDegree);
}

 


int main()
{
    int n,m;
    int *weighted;
    ADJ *lstAdj;
    
    loadData(&n,&m,&weighted,&lstAdj);
    process(n,m,weighted, lstAdj);
    return 0;
}