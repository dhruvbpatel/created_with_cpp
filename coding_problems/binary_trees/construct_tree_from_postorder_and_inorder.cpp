/*

Given Postorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.

Note: Assume binary tree contains only unique elements.
Input format :

Line 1 : n (Total number of nodes in binary tree)

Line 2 : Post order traversal

Line 3 : Inorder Traversal

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :
8
8 4 5 2 6 7 3 1
4 8 2 5 1 6 3 7

Sample Output :
1 
2 3 
4 5 6 7 
8

*/








// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/

// BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
//     // Write your code here
    
    
// }


BinaryTreeNode<int> *buildTreeWithPost(int *in,int *pos,int inS,int inE,int posS,int posE){

    
    
		if(inS>inE || posS>posE){
			return NULL;
		}

	int rootData = pos[posE];

	int rootIndex = -1;	
	for(int i=inE;i>=inS;i--){
		if(in[i]==rootData){
			rootIndex  = i;
			break;
		}
	}





	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPosS = posS;
	int lPosE = lInE-lInS + lPosS;
	int rInS = rootIndex + 1;
	int rInE = inE;
	int rPosS = lPosE+1;
	int rPosE= posE-1 ;

BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData) ;
root->left = buildTreeWithPost(in,pos,lInS,lInE,lPosS,lPosE);
root->right = buildTreeWithPost(in,pos,rInS,rInE,rPosS,rPosE);

return root;

}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *post, int postLen, int *in, int inLen) {
    // Write your code here

	return buildTreeWithPost(in,post,0,inLen-1,0,postLen-1);


}
