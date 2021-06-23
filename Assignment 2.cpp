int k = 0;
    for(int i = 0; i < n;i++){
        if(a[0] == b[i])
            k = i;
    }
    bool ans = false;
    for(int i = 0; i < (n-k);i++){
        if(a[i] == b[(i+k)])
            ans = true;
        else
            ans = false;
    }
    for (int j = (n-k); j < n; j++){
        if (a[j] == b[(j+k)%n])
            ans = true;
        else
            ans = false;
    }
    return ans;