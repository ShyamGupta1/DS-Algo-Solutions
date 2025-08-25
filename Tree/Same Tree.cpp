class Solution
{
public:
    void traverse(TreeNode *root, string &str)
    {
        if (!root)
        {
            str += ".";
            return;
        }
        str += to_string(root->val);
        traverse(root->left, str);
        traverse(root->right, str);
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        string s1 = " ";
        string s2 = " ";
        traverse(p, s1);
        traverse(q, s2);
        return s1 == s2 ? 1 : 0;
    }
};