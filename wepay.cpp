
/*
 * Complete the function below.
 */
bool alert(vector <int> inputs, int windowSize, float allowedIncrease) {
    float avg = 0.0, minavg = FLT_MAX, maxavg = 0.0; float sum =0;
    //considering case where inputsize of smaller thatn window size
    //if windowSize is smaller than inputSize, we iterate only once and check if any element is greater thatn the average*allowedIncrease.
    //if it is return true else false.
    if(inputs.size()<windowSize)
    {
        for(int i=0;i<inputs.size();i++)
        {
            sum+=inputs[i];
        }
        avg = float(sum/(float)inputs.size());
        for(int i=0;i<inputs.size();i++)
        {
            if((float)inputs[i] > float(avg*allowedIncrease))
                return true;
        }
    }
    else
    {
        //map holds the keys which are greater than the average * allowedIncrease
        //minavg holds the minimun average and maxavg holds maximum average. 
        //They are used to check if the minimum avg we have doung until now is smaller than maxavg/allowedincrease
        map<int, int> m;
        for(int i=0;i<windowSize;i++)
        {
            sum+=inputs[i];
        }
        //iterating over all windows
        //not described in the problem so not taking windows at the end which are smaller than the predefined windowSize
        //in every iterating we save minavg and maxavg and we do not recompute sum, instead we use sliding window approach for sum where 
        //we remove first number and add the last number that preserves the sum of the new sliding window.
        for(int i=0;i<inputs.size()-windowSize+1;i++)
        {
            cout<<i<<" =i \t";
            if(i!=0)
            sum += inputs[i+windowSize-1];
            avg = float(sum / (float)windowSize);
            minavg = min(avg, minavg);
            maxavg = max (avg, maxavg);
            //if maximum avg is > min avg*increaseAllowed, return true
            if(maxavg > minavg * allowedIncrease) return true;
            //we add in the map if the value of a certain element in the inputs is > avg*increaseAllowed.
            for(int j=0;j<windowSize;j++)
            {
                if(float( inputs[i+j] ) > avg * allowedIncrease)
                {
                    if(m.count(i+j)==0) 
                        m[i+j]=1;
                    else
                        m[i+j]++;
                }
            }
            cout<<sum<<" sum"<<endl;
            cout<<avg<<" avg / "<<minavg<<" minavg / "<<maxavg<<" / \n"; 
            sum -= inputs[i];
        }
        cout<<m.size()<<endl;
        vector<int> a; 
        int j = 0;
        //making a vector that saves which numbers are found how many times in all windows so we can compare at the end.
        for(int i=1;i<=inputs.size();i++)
        {
            if(i<=windowSize) {  j++; a.push_back(j);  }
            else if(i>inputs.size()-windowSize) { a.push_back(j); j--;}
            else a.push_back(j);
        }
        //for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
        //comparision with the array that we made.
        for(int i=0;i<a.size();i++)
        {
            if(m[i]==a[i]) return true;
        }
    }
    //Done :). Have a nice day.
    return false; 
}
