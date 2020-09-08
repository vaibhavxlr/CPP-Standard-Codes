void helper(Node *root, int dist, int level, map<int, pair<int, int> > &mp) {
    if(root == NULL)
        return;
        
    if(mp.find(dist) != mp.end() && mp[dist].first <= level) 
            mp[dist] = {level, root -> data};
    else if(mp.find(dist)  == mp.end())
            mp[dist] = {level, root -> data};
            
    helper(root -> left, dist - 1, level + 1, mp);
    helper(root -> right, dist + 1, level + 1, mp);
}

vector <int> bottomView(Node *root)
{
   map<int, pair<int, int> > mp;
   helper(root, 0, 1, mp);
   // Your Code Here
   vector<int> ans;
   
   for(auto itr : mp) {
       
       ans.push_back(itr.second.second);
   }
   
   return ans;
}
