#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<float>> generate_SAW(int steps,int dimension)
{
    if (dimension==2)
    {
        vector<vector<float>> position_array(steps+1,vector<float>(2));
        
        position_array[0][0]=0;
        position_array[0][1]=0;
        int n=0;
        int control=0;
        while(n<=steps)
        {
            random_device rd;  //Will be used to obtain a seed for the random number engine
            mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
            uniform_real_distribution<> dis(0, 1);
            float theta=dis(gen)*2*M_PI;
            float move_x=cos(theta);
            float move_y=sin(theta);
            float p_x=position_array[n][0]+move_x;
            float p_y=position_array[n][1]+move_y;
            cout<<p_x<<p_y<<endl;
            int count=0;
            for(int i=0;i<=n;i++)
            {
                float distance=sqrt((p_x-position_array[i][0])*(p_x-position_array[i][0])+(p_y-position_array[i][1])*(p_y-position_array[i][1]));
                cout<<distance<<endl;
                if (distance<0.99)
                {count=1;
                
                break;}
            }
            if(count==1)
            {   control+=1;
                if (control>200)
                    break;
                else
                    continue;
            }
            else
            {
                control=0;
                n=n+1;
                position_array[n][0]=p_x;
                position_array[n][1]=p_y;
            }



        }
        if(n<steps)
        {
            cout<<"This array is stuck at "<<n<<" steps"<<endl;
            return position_array;
        }
        else
            return position_array;
    }
}

int main()
{
    vector<vector<float>> a=generate_SAW(100,2);
    cout<<a[0][0]<<endl;
    return 0;
}