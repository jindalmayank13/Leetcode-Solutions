class Solution {
public:

string removespaces(string s)
{
    string st;
int n=s.size();
int i=0;
while(i<n&&s[i]==' ')
{
    i++;
}
int j=n-1;
while(j>=0&&s[j]==' ')
{
    j--;
}
while(i<=j)
{
    if(s[i]==' ')
    {
        while(i<=j&&s[i]==' ')
        {
            i++;
        }
        st.push_back(' ');
    }
    else{
        st.push_back(s[i]);
        i++;
    }
}
return st;
}
    string reverseWords(string s) {

  s=removespaces(s);
        string ans="";
        string temp="";
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]==' ')
            {
                reverse(temp.begin(),temp.end());
                ans=ans+temp;
                ans.push_back(' ');
                temp="";
            }
            else
            {
                temp.push_back(s[i]);
            }

        }
        reverse(temp.begin(),temp.end());
        ans=ans+temp;
        return ans;
 
    }
};