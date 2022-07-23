int lca(Node* root, Node** lca, vector<int> cmplist, bool& found)
{
	if ( found ) return 0;
	
	if ( cmp(root->value, cmplist) )
		{
			return 1;
		}
	
	int match = lca(root->left, lca, cmplist, found) + lca(root->right, lca, cmplist, found);
	if ( !found && match == 2 )
		{
			*lca = root;
			found = true;
			return 2;
		}
	else
		{
			return match;
		}
}
