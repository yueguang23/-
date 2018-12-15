#define MAXVEX 20
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct {
	int arcs[MAXVEX][MAXVEX];
	char vex[MAXVEX];
	int vexnum;
	int arcnum;
} AdjMatrix;
//¥¥Ω®Õº 
void create(AdjMatrix *G) {
	int i, j, k, v1, v2;
	char vex1, vex2;
	scanf("%d %d", &G->vexnum, &G->arcnum);
	fflush(stdin);
	for(i = 0;i < G->vexnum;i++) {
		for(j = 0;j < G->vexnum;j++) {
			G->arcs[i][j] = 0;
		}
	}
	
	for(i = 0;i < G->vexnum;i++) {
		scanf("%c",&G->vex[i]);
	}
	/*
	for(i = 0;i < G->vexnum;i++) {
		printf("%c",G->vex[i]);
	}
	*/
	for(k = 0;k < G->arcnum;k++) {
		fflush(stdin);
		scanf("%c%c", &vex1, &vex2);
		fflush(stdin);
		
		for(i = 0;i < G->vexnum;i++) {
			if(G->vex[i] == vex1) {
				v1 = i;
			    break;
			}
		}
		
		
		for (i = 0;i < G->vexnum;i++) {
			if(G->vex[i] == vex2) {
				v2 = i;
				break;
			}
		}
		
		G->arcs[v1][v2] = 1;	
	}
	/*
	for(i = 0;i < G->vexnum;i++) {
		for( j = 0;j < G->vexnum;j++) {
			printf("%d",G->arcs[i][j]);
		}
		printf("\n");
	}
	*/
	
}

int visited[MAXVEX];
void DFS(AdjMatrix *G,int vi) {
	int vj;
	visited[vi] = TRUE;
	for(vj = 0;vj < G->vexnum;vj++) {
		if(!visited[vj]&&G->arcs[vi][vj] == 1) {
			DFS(G,vj);
		}
	}
}

//±È¿˙Õº 

int TraverseG(AdjMatrix *G) {
	int i;
	int e = 0;
	for(i = 0;i < G->vexnum;i++) {
		visited[i] = FALSE;
	}
	for(i = 0;i < G->vexnum;i++) {
		if(!visited[i]) {  
			e++;
			DFS(G,i);
		}
	}
	return e;
}

void main() {
	AdjMatrix *G;
	G = (AdjMatrix *)malloc(sizeof(AdjMatrix));
	create(G);
	printf("%d",TraverseG(G));
}


