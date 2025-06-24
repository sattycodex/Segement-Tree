#include <bits/stdc++.h>
using namespace std;

class Segment{
    vector<int> node;
    vector<int> arr;
    public:
        Segment(vector<int> &arr){
            int n=arr.size();
            this->node.resize(4*n,0);
            this->arr=arr;
        }
        
        void build(int pos,int start,int end){
            if(start==end){
                node[pos]=arr[start];
            }else{
                int mid=(start+end)/2;
                build(pos*2,start,mid);
                build(pos*2+1,mid+1,end);
                node[pos]=max(node[pos*2],node[pos*2+1]);
            }
        }
        int query(int pos,int start,int end,int l,int r){
            if(end<l ||r<start )return -1e9;
            else if(start==end){
                return arr[start];
            }
            else if(l<=start && r>=end){
                return node[pos];
            }
            int mid=(start+end)/2;
            int ll=query(pos*2,start,mid,l,r);
            int rr=query(pos*2+1,mid+1,end,l,r);
            return max(ll,rr);
        }
        
        void pointUpdate(int pos,int start,int end,int idx,int val){
            if(start>idx || end<idx)return;
            else if(start==end){
                node[pos]=val;
                arr[start]=val;
                return;
            }
            int mid=(start+end)/2;
            pointUpdate(pos*2,start,mid,idx,val);
            pointUpdate(pos*2+1,mid+1,end,idx,val);
            node[pos]=max(node[pos*2],node[pos*2+1]);
        }
    
};

int main()
{
    vector<int> arr={8,6,3,7,1,9,4,2};
    int n=arr.size();
    Segment* segment=new Segment(arr);
    segment->build(1,0,n-1);
    cout<<segment->query(1,0,n-1,0,4)<<endl;
    segment->pointUpdate(1,0,n-1,3,20);
    cout<<segment->query(1,0,n-1,2,3)<<endl;
    cout<<segment->query(1,0,n-1,0,4)<<endl;
    

    return 0;
}
