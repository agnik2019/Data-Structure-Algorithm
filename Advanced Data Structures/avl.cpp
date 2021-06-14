#include <iostream>
struct TreeNode {
      int data;
      int height;
      TreeNode *lchild;
      TreeNode *rchild;
      TreeNode() : data(0), lchild(nullptr), rchild(nullptr) {}
      TreeNode(int x) : data(x), lchild(nullptr), rchild(nullptr) {}
      TreeNode(int x, TreeNode *lchild, TreeNode *rchild) : data(x), lchild(lchild), rchild(rchild) {}
  };
TreeNode *root=NULL;
int NodeHeight(struct TreeNode *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
int BalanceFactor(struct TreeNode *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl-hr;
}
TreeNode * LLRotation(struct TreeNode *p)
{
    TreeNode *pl=p->lchild;
    TreeNode *plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);
    if(root==p)
        root=pl;
    return pl;
}
TreeNode * LRRotation( TreeNode *p)
{
    TreeNode *pl=p->lchild;
    TreeNode *plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
    if(root==p)
         root=plr;
    return plr;
}
TreeNode * RRRotation(TreeNode *p)
{
    return NULL;
}
TreeNode * RLRotation(TreeNode *p)
{
    return NULL;
}
TreeNode *RInsert(TreeNode *p,int key)
{
    TreeNode *t=NULL;
    if(p==NULL)
    {
        t=new TreeNode();
        t->data=key;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key < p->data)
        p->lchild=RInsert(p->lchild,key);
    else if(key > p->data)
        p->rchild=RInsert(p->rchild,key);
    p->height=NodeHeight(p);
    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        return LLRotation(p);
    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        return LRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        return RRRotation(p);
    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        return RLRotation(p);
    return p;
}
int main()
{
    root=RInsert(root,50);
    RInsert(root,10);
    RInsert(root,20);
    return 0;
}