void maximoMinimo(int *v, int N, int *maximo, int *minimo)
{
    int i, j,temporaria;
    for(i=0; i < N; ++i)
    {
        for(j= i + 1; j < N; ++j)
        {
            if(v[i] > v[j])
            {
                temporaria = v[i];
                v[i] = v[j];
                v[j] = temporaria;
            }
        }
    }
    *maximo = v[N-1];
    *minimo = v[0];

}
