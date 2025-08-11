/*
1.1.7. Dijkstra's Shortest Path Algorithm


Sample Test Cases
Test case 1
Enter·the·number·of·vertices·:·4	
Enter·the·number·of·edges·:·5	
Enter·source·:·1	
Enter·destination·:·2	
Enter·weight·:·4	
Enter·source·:·1	
Enter·destination·:·4	
Enter·weight·:·10	
Enter·source·:·1	
Enter·destination·:·3	
Enter·weight·:·6	
Enter·source·:·2	
Enter·destination·:·4	
Enter·weight·:·5	
Enter·source·:·3	
Enter·destination·:·4	
Enter·weight·:·2	
Enter·the·source·:1	
Node→Distance→Path⏎	
···2→·······4→2<-1⏎	
···3→·······6→3<-1⏎	
···4→·······8→4<-3<-1⏎	
Test case 2
Enter·the·number·of·vertices·:·5	
Enter·the·number·of·edges·:·6	
Enter·source·:·1	
Enter·destination·:·2	
Enter·weight·:·2	
Enter·source·:·1	
Enter·destination·:·5	
Enter·weight·:·3	
Enter·source·:·2	
Enter·destination·:·4	
Enter·weight·:·4	
Enter·source·:·2	
Enter·destination·:·3	
Enter·weight·:·7	
Enter·source·:·4	
Enter·destination·:·3	
Enter·weight·:·2	
Enter·source·:·5	
Enter·destination·:·4	
Enter·weight·:·1	
Enter·the·source·:2	
Node→Distance→Path⏎	
···1→·····INF→NO·PATH⏎	
···3→·······6→3<-4<-2⏎	
···4→·······4→4<-2⏎	
···5→·····INF→NO·PATH⏎	
Test case 3
Enter·the·number·of·vertices·:·4	
Enter·the·number·of·edges·:·5	
Enter·source·:·1	
Enter·destination·:·2	
Enter·weight·:·4	
Enter·source·:·3	
Enter·destination·:·2	
Enter·weight·:·5	
Enter·source·:·4	
Enter·destination·:·1	
Enter·weight·:·1	
Enter·source·:·4	
Enter·destination·:·2	
Enter·weight·:·3	
Enter·source·:·4	
Enter·destination·:·3	
Enter·weight·:·8	
Enter·the·source·:1	
Node→Distance→Path⏎	
···2→·······4→2<-1⏎	
···3→·····INF→NO·PATH⏎	
···4→·····INF→NO·PATH⏎*/



#include <limits.h> 
            }
        }
    }

	printf("Node\tDistance\tPath\n");
	for (int i = 1; i <= n; i++) {
	    if (i == startnode) continue;
	
	    // Print node with 3 leading spaces and arrow
	    printf("   %d\t", i);
	
	    if (distance[i] == INFINITY) {
	        // 7 spaces after arrow
	        printf("     INF\tNO PATH\n");
	    } else {
	        // Print distance followed by 7 spaces, then arrow and path
	        printf("       %d\t", distance[i]);
	        printPath(parent, i);
	        printf("\n");
	    }
	}
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 
