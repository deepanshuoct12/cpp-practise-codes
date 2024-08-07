// C++ program to find smallest window containing
// all characters of a pattern.
#include<bits/stdc++.h>
using namespace std;

const int no_of_chars = 256;

// Function to find smallest window containing
// all characters of 'pat'
string findSubString(string str, string pat)
{
	int len1 = str.length();
	int len2 = pat.length();

	// check if string's length is less than pattern's
	// length. If yes then no such window can exist
	if (len1 < len2)
	{
		cout << "No such window exists";
		return "";
	}

	int hash_pat[no_of_chars] = {0};
	int hash_str[no_of_chars] = {0};

	// store occurrence ofs characters of pattern
	for (int i = 0; i < len2; i++)
		hash_pat[pat[i]]++;

	int start = 0, start_index = -1, min_len = INT_MAX;

	// start traversing the string
	int count = 0; // count of characters
	for (int j = 0; j < len1 ; j++)
	{
		// count occurrence of characters of string
		hash_str[str[j]]++;

		// If string's char matches with pattern's char
		// then increment count
		if (hash_pat[str[j]] != 0 &&
			hash_str[str[j]] <= hash_pat[str[j]] )
			count++;

		// if all the characters are matched
		if (count == len2)
		{
			// Try to minimize the window i.e., check if
			// any character is occurring more no. of times
			// than its occurrence in pattern, if yes
			// then remove it from starting and also remove
			// the useless characters.
			while ( hash_str[str[start]] > hash_pat[str[start]]
				|| hash_pat[str[start]] == 0)
			{

				if (hash_str[str[start]] > hash_pat[str[start]])
					hash_str[str[start]]--;
				start++;
			}

			// update window size
			int len_window = j - start + 1;
			if (min_len > len_window)
			{
				min_len = len_window;
				start_index = start;
			}
		}
	}

	// If no window found
	if (start_index == -1)
	{
	cout << "No such window exists";
	return "";
	}

	// Return substring starting from start_index
	// and length min_len
	return str.substr(start_index, min_len);
}

// Driver code
int main()
{
	string str = "this is a test string";
	string pat = "tist";

	cout << "Smallest window is : \n"
		<< findSubString(str, pat);
	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;

int minwindow(string str,string pat){

int len1=str.length();
int len2=pat.length();

if(len1<len2)
    return -1;

    int hash_str[100]={0};
    int hash_pat[100]={0};
    int minlen=INT_MAX;
    int start_index=-1;
  int count=0;
  int start=0;
    for(int i=0;i<len1;i++)
    {

        hash_str[str[i]]+=1;

        if((hash_pat[str[i]]!=0) && (hash_str[str[i]]<=hash_pat[str[i]]))
        {
            count++;
        }
        if(count==len2)
        {
            while(hash_str[str[start]]>hash_pat[str[i]]  || hash_pat[str[start]]==0)
            {
                if( hash_str[str[start]] > hash_pat[str[start]] )
                {
                    hash_str[str[start]]=-1;
                }
                start+=1;
            }

            int len_window=i-start+1;
            if(minlen>len_window)
            {
                minlen=len_window;
                start_index=start;
            }
        }
    }
    if(start_index==-1)
        cout<<"no window";

    return str.substr(start_index,minlen);

}
int main(){

    string str,pat;
    cin>>str>>pat;
    cout<<minwindow(str,pat);
return 0;
}
*/
