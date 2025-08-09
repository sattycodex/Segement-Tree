class Heap{
    private:
      vector<int> heap;
      int temp;
      int sz=0;
    public:
      void swap(int a,int b){
          int t=heap[a];
          heap[a]=heap[b];
          heap[b]=t;
      }
      Heap(vector<int>&nums){
          int n=nums.size();
          heap.resize(n);
          sz=n;
          temp=-1;
          for(auto val:nums){
              insert(val);
          }
      }
      
      //insert at last index of heap array
      void insert(int val){
          temp++;
          heap[temp]=val;
          int ind=temp;
          while((ind-1)/2>=0 && heap[(ind-1)/2]<val){
              swap(ind,(ind-1)/2);
              ind=(ind-1)/2;
          }
      }
      
      
      //swap first and last element and adjust the position of root element
      void delet(){
          swap(0,temp);
          temp--;
          int ind=0;
          while(ind<=temp){
              int left=2*ind+1;
              int right=2*ind+2;
              //check left and right exist
              if(left<=temp && right<=temp){
                  //swap only if parent element is less than either left or right child
                  if(heap[left]>heap[right] && heap[left]>heap[ind]){
                      swap(left,ind);
                      ind=left;
                  }else if(heap[left]<heap[right] && heap[right]>heap[ind]){
                      swap(right,ind);
                      ind=right;
                  }else break;
                  
              }//check left exist
              else if(left<=temp){
                  //only swap if left element is greater than parent element
                  if(heap[left]>heap[ind]){
                      swap(left,ind);
                      ind=left;
                  }else break;
              }//if left not exit right will definitly not exist
              else break;
          }
      }
      
      void display(){
          for(auto h:heap)cout<<h<<" ";
      }
      void heapSort(){
          for(int i=0;i<sz;i++){
              delet();
          }
      }
};
