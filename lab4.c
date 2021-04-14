
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>



void meniu()
{
    printf("1. Alocarea dinamica a memoriei pentru tablourile bidimensionale:\n");
    printf("2. Introducerea elementelor tabloului de la tastatura:\n");
    printf("3. Completarea tabloului cu valori aleatorii:\n");
    printf("4. Sortarea elementelor tablourilor(conform variantelor):\n");
    printf("5. Afisarea elementelor tabloului la ecran:\n");
    printf("6. Eliberarea memoriei alocate pentru tablou:\n");
    printf("7. Iesire din program.\n");
}

int ** memory_alloc(int n, int m)
{
    int i;
    int** matrice=(int **)malloc(n*sizeof (int*));
    if(matrice==NULL)
        return matrice;
    for(int i=0; i<n; i++)
    {
        matrice[i]=(int*)malloc(m*sizeof(int));
        if(matrice[i]==NULL)
            return NULL;
    }
    return matrice;
}

void introduction_of_elements(int **matrice,int n,int m)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",&matrice[i][j]);
        }
    }

}

void random(int **matrice, int n, int m)
{
    int i,j;
    srand(time(NULL));
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            matrice[i][j]=rand()%101*pow(-1,rand()%2);
    }
}

void sorting_items(int **matrice, int n,int m)
{
    int i,k,t,j,rc;

    for(k=0;k<m;k++ )
	{   t=matrice[i][k];
		for(j=k-1; j>=0 && t>matrice[i][j]; j--)
		{
		matrice[i][j+1]=matrice[i][j];
		}
		matrice[i][j+1]=t;

	}
        i=rc;

}
        void  displaying_items(int **matrice,int n,int m)
        {
            int i,j;
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                    printf("%d   ",matrice[i][j]);
                printf("\n");
            }

        }

        void memory_release(int **matrice, int m)
        {
            int j;
            for (j=0; j<m; j++)
            {
                free(matrice[j]);
            }
            free(matrice);
        }

        void main()
        {
            int n,m,temp;
            printf("Introduceti nr. de linii: ");
            scanf("%d",&n);
            printf("Introduceti nr. de coloane: ");
            scanf("%d",&m);
            int **matrice=NULL;

            do
            {
                meniu();
                scanf("%d",&temp);

                switch(temp)
                {
                case 1:
                    matrice=memory_alloc(n,m);
                    break;

                case 2:
                    introduction_of_elements(matrice,n,m);
                    break;

                case 3:
                    random(matrice,n,m);
                    break;

                case 4:
                    sorting_items(matrice,n,m);
                    break;

                case 5:
                    displaying_items(matrice,n,m);
                    break;

                case 6:
                    memory_release(matrice,m);
                    break;

                case 7:
                    return 0;
                    break;
                }
            }
            while(temp!=0);
        }



