#include "iostream"
#include "vector"
using namespace std;

class RailFence
{
    private:
        vector<string> PT;
        vector<string> RAIL1;
        vector<string> RAIL2;
        vector<string> CT;
        vector<string> DECRYPT_PT;
    public:
        void getData()
        {
            string str;
            cout<<"Enter Plain Text:  ";
            getline(cin, str);
            for(int i = 0; i<str.length(); i++)
            {
                string val = string(1,str.at(i));
                PT.push_back(val);
            }
        }
        void encrypt()
        {
            vector<string>::iterator itr;
            for(itr = PT.begin();itr != PT.end(); itr+=2)
            {
                RAIL1.push_back(*(itr));
                RAIL2.push_back(*(itr+1));
            }
            for(itr = RAIL1.begin(); itr != RAIL1.end(); itr++)
            {
                CT.push_back(*itr);
            }
            for(itr = RAIL2.begin(); itr != RAIL2.end(); itr++)
            {
                CT.push_back(*itr);
            }
        }
        void decrypt()
        {
            int n = CT.size();
            int gap = n/2;
            for(int i=0; i<gap; i++)
            {
                DECRYPT_PT.push_back(CT[i]);
                DECRYPT_PT.push_back(CT[i+gap]);
            }
        }
        void showPT()
        {
            vector<string>::iterator itr;
            for(itr = PT.begin();itr != PT.end(); itr++)
            {
                cout<<*itr;
            }
            cout<<endl;
        }
        void showDecryptPT()
        {
            vector<string>::iterator itr;
            for(itr = DECRYPT_PT.begin();itr != DECRYPT_PT.end(); itr++)
            {
                cout<<*itr;
            }
            cout<<endl;
        }
        void showCT()
        {
            vector<string>::iterator itr;
            for(itr = CT.begin();itr != CT.end(); itr++)
            {
                cout<<*itr;
            }
            cout<<endl;
        }
};

int main()
{
    
    RailFence R;
    R.getData();

    cout<<endl;
    
    cout<<"Plain Text:  ";
    R.showPT();

    R.encrypt();
    cout<<"Cipher Text:  ";
    R.showCT();
    
    R.decrypt();
    cout<<"Decrypted Cipher Text:  ";
    R.showDecryptPT();
    
    return 0;
}