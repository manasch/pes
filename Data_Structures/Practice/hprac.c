void bot_heap(int *h, int n)
{
    int i, j, k, key;
    
    for (k = (n - 1) / 2; k >= 0; k--)
    {
        j = k;
        key = h[j];
        i = (2 * j) + 1;
        
        while (i <= n)
        {
            if (i + 1 <= n)
            {
                if (h[i + 1] > h[i] )
                    i++;
            }
            
            if (key < h[i])
            {
                h[j] = h[i];
                j = i;
                i = (2 * j) + 1;
            }
            else
                break;
        }
        h[j] = key;
    }
}

void top_down (int *h, int n)
{
    int i, j, k, key;
    for (k = 1; k <= n; k++)
    {
        i = k;
        key = h[i];
        j = (i - 1) / 2;
        while ((i > 0) && (key > h[j])
        {
            h[i] = h[j];
            i = j;
            j = (i - 1) / 2;
        }
        h[i] = key;
    }
}

void pqinsert(int *h, element temp, int *count)
{
    int i;
    i = *count;
    h[*count] = temp;
    ++*count;
    j = (i - 1) / 2;
    while ((i > 0) && (temp.pty < h[i].pty))
    {
        h[i] = h[j];
        i = j;
        j = (i - 1) / 2;
    }
    h[i] = temp;
}
