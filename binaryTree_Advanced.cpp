#include"BinaryTrees_basic.cpp"
#include<iostream>
using namespace std;


Node* PreAndInOrderTree(int Pre[],int In[],int &startPre, int startIn,int endIn){
    if(startIn==endIn){
        return  NULL;
    }
    Node* root= new Node(Pre[startPre]);
    int i =0;
    while(In[i]!=root->data){
        i++;
    }
    startPre++;
    root->left=PreAndInOrderTree(Pre,In,startPre,0,i-1);
    cout<<"Yes"<<startIn<<endl;
    root->right=PreAndInOrderTree(Pre,In,startPre,i+1,endIn);
    cout<<"Yes again"<<startIn<<endl;
    return root;    
    
}
int main(){
    int Pre[9] ={1,2,4,5,8,3,6,7,9}, In[9]={4,2,8,5,1,6,3,8,9};
    /*cout<<"Enter data for PreOrder Array:\n";
    for(int i =0 ;i<9;i++){
        cin>>Pre[i];
    }
    cout<<"Enter data for InOrder Array:\n";
    for(int i =0 ;i<9;i++){
        cin>>In[i];
    }*/
    cout<<" Pre Order Array: \n";
    for(int i=0;i<9;i++){
        cout<<Pre[i]<<" ";
    }
    
    cout<<endl;
    cout<<"In Order Array: \n";
    for(int i=0;i<9;i++){
        cout<<In[i]<<" ";
    }
    cout<<endl;
    int index=0;
    Node* root=PreAndInOrderTree(Pre,In,index,0,8);
    cout<<"Start";
    LevelOrderTraversal(root);
    return 0;
}
// 1 2 4 5 8 3 6 7 9 
// 4 2 8 5 1 6 3 8 9