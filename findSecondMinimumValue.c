#define _CRT_SECURE_NO_WARNINGS 1

/*671. 二叉树中第二小的节点
给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。

更正式地说，root.val = min(root.left.val, root.right.val) 总成立。

给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

 

示例 1：


输入：root = [2,2,5,null,null,5,7]
输出：5
解释：最小的值是 2 ，第二小的值是 5 。
示例 2：


输入：root = [2,2,2]
输出：-1
解释：最小的值是 2, 但是不存在第二小的值。*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };



//   第一种
int findMin(struct TreeNode* root,int data )
{
if(!root)
return -1;
if(root->val>data)
return root->val;
int left=findMin(root->left,data);
int right=findMin(root->right,data);
if(left==-1)
return right;
if(right==-1)
return left;
return right>left?right:left;
}

int findSecondMinimumValue(struct TreeNode* root)
{
return findMin(root,root->val);
}
*/


//第二种
void dfs(struct TreeNode* root, int* nums, int* numsSize){
	if (root->left == NULL && root->right == NULL){
		nums[*numsSize] = root->val;
		(*numsSize)++;
		return;
	}

	nums[*numsSize] = root->val;
	(*numsSize)++;
	dfs(root->left, nums, numsSize);
	dfs(root->right, nums, numsSize);
}

int findSecondMinimumValue(struct TreeNode* root){
	int* nums = (int*)malloc(sizeof(int)* 50);
	int numsSize = 0;
	dfs(root, nums, &numsSize);
	int min = nums[0];
	int base = nums[0];

	for (int i = 0; i < numsSize; i++){
		if (nums[i] != min){
			base = nums[i];
		}
	}

	for (int i = 0; i < numsSize; i++){
		if (nums[i] != nums[0]){
			base = base < nums[i] ? base : nums[i];
		}
	}

	return base == nums[0] ? -1 : base;
}