#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode*> children;

TreeNode(T data){
    this->data = data;

}

~TreeNode(){
    for(int i=0;i<children.size();i++){
        delete children[i];

    }
}
// now just write delete root at the end of main function
};

// mush efficient take input
TreeNode<int> *takeInputLevelWise(){
    int rootData;
    cout << "Enter root Data:" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size()!=0){
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"enter num of child of "<<front->data <<endl;
        int numChild;
        cin>>numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout<<"Enter "<<i <<"child of "<<front->data<<endl;
            cin>>childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child); // connecting
            pendingNodes.push(child);   // add child in queue;

        }
        
    }
    return root;

}

void printLevelWise(TreeNode<int> *root)
{

    if (root == NULL)
    {
        return; // edge case
    }

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        cout << pendingNodes.front()->data << ":"; // print 1st root

        for (int i = 0; i < pendingNodes.front()->children.size(); i++)
        {


            cout << pendingNodes.front()->children[i]->data;
            if (i != pendingNodes.front()->children.size() - 1)
            {
                cout << ","; // for
            }

            pendingNodes.push(pendingNodes.front()->children[i]);
        }
        cout << endl;

        pendingNodes.pop();
    }
}


int numNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int> *root)
{
    
    int ans = 0;
    for(int i=0;i<root->children.size();i++){
        ans = root->children[i]->data +sumOfNodes(root->children[i]);
    }
return ans - root->data;

}


void printTree(TreeNode<int> *root){
    if(root==NULL){
        return;   // edge case 
    }

     cout<<root->data <<":"   ;
     for(int i=0;i<root->children.size();i++){
         cout<<root->children[i]->data<<",";
     }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }

}

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postOrder(TreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }

    cout << root->data << " ";
}

// normal (complex) take input
TreeNode<int> *takeInput(){
    int rootData;
    cout<<"Enter root Data:"<<endl;
    cin>>rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout<<"Enter the num of children of "<<rootData<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);

    }
    return root;
}

void printAtLevelK(TreeNode<int> *root,int k){
    
    if(root==NULL){
        return;
    }
    
    if(k==0){
        cout<<root->data<<endl;
    }

    for(int i=0;i<root->children.size();i++){
        printAtLevelK(root->children,k-1);
    }
}

    int main()
{

    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);

    cout<< numNodes(root)<<endl;


}


