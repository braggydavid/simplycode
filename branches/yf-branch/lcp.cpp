include <vector>

using namespace std;

// cmplist is an arry hold only x and y two elements
void find_lcp_traverse(Node* root, vector<int>& cmplist, vector<int>& findlist1, vector<int>& findlist2, bool& found)
{
	if ( root == NULL )
		return;
	
	findlist1.push_back(root->value);
	
	if ( cmplist.size() == 2 )
	{
		for ( int i = 0; i < cmplist.size(); ++i )
		{
			if ( root->value == cmplist[i] )
			{
				copy(findlist1.begin(), findlist1.end(), findlist2.begin());
				cmplist.erase(cmplist[i]);
				break;
			}
		}
	}
	else
	{
		if ( root->value == cmplist[0] )
		{
			found = true;
			return;
		}
	}
	
	find_lcp_traverse(root->left, cmplist, findlist1, findlist2, found);
	if ( found ) return;
	if ( root->left )
	{
		findlist1.pop_back();
	}
	find_lcp_traverse(root->right, cmplist, findlist1, findlist2, found);
	if ( found ) return;
	if ( root->right )
	{
		findlist1.pop_back();
	}
}

vector<int> find_lcp_no_bs(Node *root, int x, int y)
{
	vector<int> seq1;
	vector<int> seq2;
	
	vector<int> cmplist;
	cmplist.push_back(x);
	cmplist.push_back(y);
	
	bool found = false;
	
	find_lcp_traverse(root, cmplist, seq1, seq2, found);
	
	vector<int> result;
	if ( cmplist.size() == 0 )
	{
		// this is just to find the common part of the two vectors
		for ( int i = 0; i < seq1.size() && i < seq2.size(); ++i )
		{
			if ( seq1[i] != seq2[i] )
				break;
			else
				result.push_back(seq1[i]);
		}
	}
	
	return result;
}


// assume x <= y and x y both on the tree, output in lcp
void find_lcp_is_bs(int* root, int x, int y, vector<int>& lcp)
{
	if ( root == NULL )
		return;
	
	lcp.push_back(root->value);
	if ( root->value > x && root->value > y )
	{
		find_lcp_is_bs(root->left);
	}
	else if ( root->value < x && root->value < y )
	{
		find_lcp_is_bs(root->right);
	}
	else
	{
		return;
	}
}


// main function can invoke find_lcp_is_bs for find the lcp of a binary search tree
// main function can invoke find_lcp_no_bs for find the lcp of a non-binary search tree
