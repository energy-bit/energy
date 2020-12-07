#define _CRT_SECURE_NO_WARNINGS 1

/*671. �������еڶ�С�Ľڵ�
����һ���ǿ�����Ķ�������ÿ���ڵ㶼������������ÿ���ڵ���ӽڵ�����ֻ��Ϊ 2 �� 0�����һ���ڵ��������ӽڵ�Ļ�����ô�ýڵ��ֵ���������ӽڵ��н�С��һ����

����ʽ��˵��root.val = min(root.left.val, root.right.val) �ܳ�����

����������һ��������������Ҫ������нڵ��еĵڶ�С��ֵ������ڶ�С��ֵ�����ڵĻ������ -1 ��

 

ʾ�� 1��


���룺root = [2,2,5,null,null,5,7]
�����5
���ͣ���С��ֵ�� 2 ���ڶ�С��ֵ�� 5 ��
ʾ�� 2��


���룺root = [2,2,2]
�����-1
���ͣ���С��ֵ�� 2, ���ǲ����ڵڶ�С��ֵ��*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };



//   ��һ��
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


//�ڶ���
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