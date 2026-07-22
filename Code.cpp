#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int start, end;
    int sum;
    Node *left;
    Node *right;

    Node(int s, int e)
    {
        start = s;
        end = e;
        sum = 0;
        left = nullptr;
        right = nullptr;
    }
};
class SegmentTree{
private:
    Node *root;
    Node *build(vector<int> &arr, int l,int r)
    {
        Node* node = new Node(l, r);
        if(l == r){
            node -> sum = arr[l];
            return node;
        }

        int mid = (l+r)/2;

        node -> left = build(arr,l,mid);
        node -> right = build(arr,mid+1,r);

        node -> sum = node -> left ->sum + node -> right -> sum;

        return node;
    }

    // Now apply the query to the above tree.
    int query(Node* root,int l, int r)
    {
        //No Overlap
        if(root == NULL || root -> end < l || root -> start > r)
        {
            return 0;
        }

        //Complete overlap
        if(l <= root -> start && root -> end <= r){
            return root -> sum;
        }

        //Partial Overlap
        return query(root -> left, l, r) + query(root -> right , l ,r);
    }

    void update(Node* root, int idx, int val){
        if(root -> start == root -> end){
            root->sum = val;
            return;
        }

        int mid = (root -> start + root -> end)/2;

        if(idx <= mid){
            update(root -> left ,idx,val);
        }else{
            update(root -> right,idx,val);
        }

        root -> sum = root -> left -> sum + root -> right -> sum;
    }

    public:
    SegmentTree(vector<int>&arr){
        root = build(arr,0,arr.size()-1);
    }

    int rangesum(int l, int r){
        return query(root,l,r);
    }

    void printupdate(int idx, int val){
        update(root, idx, val);
    }
};
int main()
{
    vector<int> arr = {3,8,7,6,-2,-8,4,9};

    SegmentTree st(arr);

     cout << st.rangesum(1, 4) << endl; //19
    
     st.printupdate(2,10);
     cout << st.rangesum(1, 4) <<endl;//22

}
