/*任务调度的合理性：
题目：假定一个工程项目由一组子任务构成，子任务之间有的可以并行执行，有的必须在完成了其它一些子任务
    后才能执行。“任务调度”包括一组子任务、以及每个子任务可以执行所依赖的子任务集。比如完成一个专业
    的所有课程学习和毕业设计可以看成一个本科生要完成的一项工程，各门课程可以看成是子任务。有些课程
    可以同时开设，比如英语和C程序设计，它们没有必须先修哪门的约束；有些课程则不可以同时开设，因为它
    们有先后的依赖关系，比如C程序设计和数据结构两门课，必须先学习前者。
    但是需要注意的是，对一组子任务，并不是任意的任务调度都是一个可行的方案。比如方案中存在“子任务A
    依赖于子任务B，子任务B依赖于子任务C，子任务C又依赖于子任务A”，那么这三个任务哪个都不能先执行，
    这就是一个不可行的方案。你现在的工作是写程序判定任何一个给定的任务调度是否可行。
输入：第一行给出子任务数N（≤100），子任务按1~N编号。随后N行，每行给出一个子任务的依赖集合：首先给
    出依赖集合中的子任务数K，随后给出K个子任务编号，整数之间都用空格分隔。
输出：如果方案可行，则输出1，否则输出0。
思路：用二维数组存储子任务之间的关系，再用数组path和inDegree分别记录拓扑排序序列和每个任务顶点入度。
    首先可以将入度为0（执行前不用等待其他任务）的点A（可以有很多）压入path，然后将A的后继任务入度
    减一，继续上述操作。输出结果的判断条件为path内元素个数等于N。
*/
#include <iostream>
#include <vector>
using namespace std;

int N,K;
int mp[102][102]={{0}};
int path[102]={0};
int inDegree[102]={0};
bool flag[102]={0};     //记录该节点是否压入path
int cnt=0;              //记录当前path的长度

bool isEnd(){           //判断是否存在入度为0的点还没压入path
    for(int i=1;i<=N;i++){
        if(inDegree[i]==0 && flag[i]==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>K;
        for(int j=0;j<K;j++){
            int m;
            cin>>m;
            mp[m][i]=1;
        }
        inDegree[i]=K;
    }
    while(!isEnd()){
        for(int i=1;i<=N;i++){
            if(inDegree[i]==0 && flag[i]==0){       //入度为0且没被压入path
                path[cnt]=i;        //将入度为0的节点压入path
                cnt++;
                flag[i]=1;
                for(int j=1;j<=N;j++){
                    if(mp[i][j]){   //必须保证i是j的前驱任务才有意义
                        inDegree[j]--;
                    }
                }
            }
        }
    }
    if(cnt==N){
        cout<<1<<endl;
    }
    else{
        cout<<0<<endl;
    }

    return 0;
}
