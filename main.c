#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define MAX_SIZE 100
char teamA[MAX_SIZE], teamB[MAX_SIZE];//��������
int teamnum, teamA_life, teamB_life, winner = 0, changeluk;
int i, k, j;
int y, n;
i = 0;
j = 0;
y = 0;
n = 0;
teamnum = 0;



typedef struct teamates//����ü�� �̿��Ͽ� �� ������ ����
{
   char *teamname;
   int id;
   int weapon;
   int life;
} teamate;

void function(teamate member[], char name[], int num)//����ڰ� �Է��� ��ŭ �Լ��� �̿��Ͽ� ������ ���� �ο�
{
    int h;
    for (h = 0; h < num; h++)
    {
        member[h].teamname = name;
        member[h].id = h+1;
        member[h].weapon = (rand() % 3) + 1;
        member[h].life = 1;
    }
}

int main(void)//�����Լ�
{
    teamate *teamAA, *teamBB;
    srand(time(NULL));

    printf("--------------------------------------------------\n");
    printf("M:������ �����մϴ�.\n");
    printf("--------------------------------------------------\n");
    printf("\n");
    printf("M:����� �� �̸���? : ");//���� ���̸� ����
    gets(teamA);
    printf("M:����� �� �̸���? : ");//��� ���̸� ����
    gets(teamB);
    printf("M:�� ���� ������� �Է��Ͻÿ� : ");//������ ����
    scanf("%d", &teamnum);
    printf("\n");
    teamA_life = teamnum;//�� ��ü ����� ���ο����� ����
    teamB_life = teamnum;//�� ��ü ����� ���ο����� ����

    teamAA = (int *)malloc(teamnum * sizeof(teamate));//malloc�� �̿��Ͽ� �����ͺ��� ���� �Ҵ�
    teamBB = (int *)malloc(teamnum * sizeof(teamate));//malloc�� �̿��Ͽ� �����ͺ��� ���� �Ҵ�

   for (i = 0; i < teamnum; i++)//selection�Լ��� ȣ���Ͽ� �� �� ������ ���� �ο�
    {
        function(teamAA, teamA, teamnum);
        function(teamBB, teamB, teamnum);
    }
    printf("--------------------------------------------------\n");
    printf("M:������ ����� ���� �����Դϴ�. (�� ������ ���� ���� ������ �� �ֽ��ϴ�.)\n");
    printf("M:����� ����(1), ����(2), ��(3)�Դϴ�.\n");
    printf("--------------------------------------------------\n");
    printf("\n");

   for (i = 0; i < teamnum; i++)//for������ ����Ͽ� ������ �������� ���� ���
    {
        printf("���̸�:%s, id:%d, ����:%d, ���:%d\n", teamAA[i].teamname, teamAA[i].id, teamAA[i].weapon, teamAA[i].life);
        printf("\n");
    }
    printf("--------------------------------------------------\n");
    printf("M:������ ��� ���� �����Դϴ�. (�� ������ ���� ���� ������ �� �ֽ��ϴ�.)\n");
    printf("M:����� ����(1), ����(2), ��(3)�Դϴ�.\n");
    printf("--------------------------------------------------\n");
    printf("\n");

    for (k = 0; k < teamnum; k++)//for������ ����Ͽ� ����� �������� ���� ���
    {
        printf("���̸�:%s, id:%d, ����:%d, ���:%d\n", teamBB[k].teamname, teamBB[k].id, teamBB[k].weapon, teamBB[k].life);
        printf("\n");
    }
    printf("--------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("--------------------------------------------------\n");
    printf("M:���ӽ���!!!!\n");
    printf("--------------------------------------------------\n");
    printf("\n");

    j = 1;
    for (i = 0, k = 0; (i < teamnum) && (k < teamnum);)//for������ ����Ͽ� ���������� ���� ����
    {
        printf("--------------------------------------------------\n");
        printf("M:�� %d����!\n", j);
        printf("M:���� ���� ��!\n");
        printf("--------------------------------------------------\n");
        printf("--------------------------------------------------\n");

        if ((teamAA[i].weapon == 1) && (teamBB[k].weapon == 3))//1 : A���� �̱�� B���� �����(����-��)
        {
            teamBB[k].life = 0;//B�� �Ѹ��� ����
            printf("\n");
            printf("M:A[%d]�� �̰���ϴ�!\n", i);
            printf("M:���⸦ �ٲٽðڽ��ϱ�?(y(0)/n(1))\n");
            scanf("%d", &y);

            if (y == 0)//���⸦ �ٲ� ���
            {
                changeluk = (rand() % 2);//������ ���⸦ �ٲ� 50%�� Ȯ�� ����

                if (changeluk == 0)//���⸦ �ٲߴϴ�
                {
                    teamAA[i].weapon = teamBB[k].weapon;//��A[i] ���Ⱑ ��B[k]����� �ٲ�
                    printf("M:A[%d]�� ���Ⱑ '%d'�� �ٲ�����ϴ�.(�� ������ ���� ���� ������ �� �ֽ��ϴ�.)\n", i, teamAA[i].weapon);
                    k = k + 1;//B�� ���� ��ü
                    teamB_life = teamB_life - 1;//��B ��� �ϳ� ����
                }
            }

            else if(y == 1);//���⸦ �ȹٲ� ���
            {
                k = k + 1;//B�� ���� ��ü
                teamB_life = teamB_life - 1;//��B ��� �ϳ� ����
            }
        }

        else if ((teamAA[i].weapon == 2) && (teamBB[k].weapon == 1))//2 : A���� �̱�� B���� �����(����-����)
        {
            teamBB[k].life = 0;//B�� �Ѹ��� ����
            printf("\n");
            printf("M:A[%d]�� �̰���ϴ�!\n", i);
            printf("M:���⸦ �ٲٽðڽ��ϱ�?(y(0)/n(1))\n");
            scanf("%d", &y);

            if (y == 0)//���⸦ �ٲ� ���
            {
                changeluk = (rand() % 2);//������ ���⸦ �ٲ� 50%�� Ȯ�� ����

                if (changeluk == 0)//���⸦ �ٲߴϴ�
                {
                    teamAA[i].weapon = teamBB[k].weapon;//��A[i] ���Ⱑ ��B[k]����� �ٲ�
                    printf("M:A[%d]�� ���Ⱑ '%d'�� �ٲ�����ϴ�.(�� ������ ���� ���� ������ �� �ֽ��ϴ�.)\n", i, teamAA[i].weapon);
                    k = k + 1;//B�� ���� ��ü
                    teamB_life = teamB_life - 1;//��B ��� �ϳ� ����
                }
            }

            else if(y == 1);//���⸦ �ȹٲ� ���
            {
                k = k + 1;//B�� ���� ��ü
                teamB_life = teamB_life - 1;//��B ��� �ϳ� ����
            }
        }

        else if ((teamAA[i].weapon == 3) && (teamBB[k].weapon == 2))//3 : A���� �̱�� B���� �����(��-����)
        {
            teamBB[k].life = 0;//B�� �Ѹ��� ����
            printf("\n");
            printf("M:A[%d]�� �̰���ϴ�!\n", i);
            printf("M:���⸦ �ٲٽðڽ��ϱ�?(y(0)/n(1))\n");
            scanf("%d", &y);

            if (y == 0)//���⸦ �ٲ� ���
            {
                changeluk = (rand() % 2);//������ ���⸦ �ٲ� 50%�� Ȯ�� ����

                if (changeluk == 0)//���⸦ �ٲߴϴ�
                {
                    teamAA[i].weapon = teamBB[k].weapon;//��A[i] ���Ⱑ ��B[k]����� �ٲ�
                    printf("M:A[%d]�� ���Ⱑ '%d'�� �ٲ�����ϴ�.(�� ������ ���� ���� ������ �� �ֽ��ϴ�.)\n", i, teamAA[i].weapon);
                    k = k + 1;//B�� ���� ��ü
                    teamB_life = teamB_life - 1;//��B ��� �ϳ� ����
                }
            }

            else if(y == 1);//���⸦ �ȹٲ� ���
            {
                k = k + 1;//B�� ���� ��ü
                teamB_life = teamB_life - 1;//��B ��� �ϳ� ����
            }
        }

        else if ((teamAA[i].weapon == 1) && (teamBB[k].weapon == 2))//4 : A���� ���� B���� �̱���(����-����)
        {
            teamAA[i].life = 0;//A�� �Ѹ��� ����
            printf("\n");
            printf("M:B[%d]�� �̰���ϴ�!\n", k);
            printf("M:���⸦ �ٲٽðڽ��ϱ�?(y(0)/n(1))\n");
            scanf("%d", &n);

            if (n == 0)//���⸦ �ٲ� ���
            {
                changeluk = (rand() % 2);//������ ���⸦ �ٲ� 50%�� Ȯ�� ����

                if (changeluk == 0)//���⸦ �ٲߴϴ�
                {
                    teamBB[k].weapon = teamAA[i].weapon;//��B[k] ���Ⱑ ��A[i]����� �ٲ�
                    printf("M:B[%d]�� ���Ⱑ '%d'�� �ٲ�����ϴ�.(�� ������ ���� ���� ������ �� �ֽ��ϴ�.)\n", k, teamBB[k].weapon);
                    i = i + 1;//A�� ���� ��ü
                    teamA_life = teamA_life - 1;//��A ��� �ϳ� ����
                }
            }

            else if(y == 1);//���⸦ �ȹٲ� ���
            {
                i = i + 1;//A�� ���� ��ü
                teamA_life = teamA_life - 1;//��A ��� �ϳ� ����
            }
        }

        else if ((teamAA[i].weapon == 2) && (teamBB[k].weapon == 3))//5 : A���� ���� B���� �̱���(����-��)
        {
            teamAA[i].life = 0;//A�� �Ѹ��� ����
            printf("\n");
            printf("M:B[%d]�� �̰���ϴ�!\n", k);
            printf("M:���⸦ �ٲٽðڽ��ϱ�?(y(0)/n(1))\n");
            scanf("%d", &n);

            if (n == 0)//���⸦ �ٲ� ���
            {
                changeluk = (rand() % 2);//������ ���⸦ �ٲ� 50%�� Ȯ�� ����

                if (changeluk == 0)//���⸦ �ٲߴϴ�
                {
                    teamBB[k].weapon = teamAA[i].weapon;//��B[k] ���Ⱑ ��A[i]����� �ٲ�
                    printf("M:B[%d]�� ���Ⱑ '%d'�� �ٲ�����ϴ�.(�� ������ ���� ���� ������ �� �ֽ��ϴ�.)\n", k, teamBB[k].weapon);
                    i = i + 1;//A�� ���� ��ü
                    teamA_life = teamA_life - 1;//��A ��� �ϳ� ����
                }
            }

            else if(y == 1);//���⸦ �ȹٲ� ���
            {
                i = i + 1;//A�� ���� ��ü
                teamA_life = teamA_life - 1;//��A ��� �ϳ� ����
            }
        }

        else if ((teamAA[i].weapon == 3) && (teamBB[k].weapon == 1))//6 : A���� ���� B���� �̱���(��-����)
        {
            teamAA[i].life = 0;//A�� �Ѹ��� ����
            printf("\n");
            printf("M:B[%d]�� �̰���ϴ�!\n", k);
            printf("M:���⸦ �ٲٽðڽ��ϱ�?(y(0)/n(1))\n");
            scanf("%d", &n);

            if (n == 0)//���⸦ �ٲ� ���
            {
                changeluk = (rand() % 2);//������ ���⸦ �ٲ� 50%�� Ȯ�� ����

                if (changeluk == 0)//���⸦ �ٲߴϴ�
                {
                    teamBB[k].weapon = teamAA[i].weapon;//��B[k] ���Ⱑ ��A[i]����� �ٲ�
                    printf("M:B[%d]�� ���Ⱑ '%d'�� �ٲ�����ϴ�.(�� ������ ���� ���� ������ �� �ֽ��ϴ�.)\n", k, teamBB[k].weapon);
                    i = i + 1;//A�� ���� ��ü
                    teamA_life = teamA_life - 1;//��A ��� �ϳ� ����
                }
            }

            else if(y == 1);//���⸦ �ȹٲ� ���
            {
                i = i + 1;//A�� ���� ��ü
                teamA_life = teamA_life - 1;//��A ��� �ϳ� ����
            }
        }

        else if (teamAA[i].weapon == teamBB[k].weapon)//7 : �����
        {
            printf("M:�����ϴ�!\n");
            printf("\n");
            printf("M:���� �����!\n");
            teamAA[i].weapon = (rand() % 3) + 1;//��A ���⺯��
            teamBB[k].weapon = (rand() % 3) + 1;//��B ���⺯��
        }
        j = j + 1;//���� ��������
    }

    printf("\n");
    printf("--------------------------------------------------\n");
    printf("M:���!!!!\n");
    printf("--------------------------------------------------\n");
    printf("\n");

    for (i = 0; i < teamnum; i++)//������ ��A ������ ���� ���
      {
        printf("���̸�:%s, id:%d, ����:%d, ���:%d\n", teamAA[i].teamname, teamAA[i].id, teamAA[i].weapon, teamAA[i].life);
        printf("\n");
      }

    for (k = 0; k < teamnum; k++)//������ ��B ������ ���� ���
      {
        printf("���̸�:%s, id:%d, ����:%d, ���:%d\n", teamBB[k].teamname, teamBB[k].id, teamBB[k].weapon, teamBB[k].life);
        printf("\n");
      }

    if (teamA_life == teamB_life)//����� ���� ���
        printf("M:�����ϴ�!\n");
    else//�ºΰ� ������ ���
        winner = (teamA_life < teamB_life) ? 1 : -1;

    if (winner > 0)//��B�� �̱��� �¸����� ���
        printf("M:�̱� ����! %s!\n", teamB);
    else if (winner < 0)//��A�� �̱��� �¸����� ���
        printf("M:�̱� ����! %s!\n", teamA);

    //malloc ����
    free(teamAA);
    free(teamBB);

    return 0;
}
