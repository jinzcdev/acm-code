//#include<cstdio>
//#include<cstring>
//typedef struct Worker {
//	char * id, *in, *out;
//}Worker;
//const int maxn = 1000;
//Worker a[maxn];
//int main() {
//
//	//int n;
//	//scanf("%d", &n);
//	//return 0;
//	char bb[] = "23:16:32";
//	char aa[] = "22:16:32";
//	printf("%d", strcmp(aa, bb));
//	getchar();
//}

#include<cstdio>
#include<cstdlib>
#include<cstring>

typedef struct Info {
	char *id, *sign_in, *sign_out;
}Info;

int main_() {
	int max = 0, min = 0, n, i, j;
	Info stu[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		Info info;

		info.id = (char *)malloc(sizeof(char));
		info.sign_in = (char *)malloc(sizeof(char));
		info.sign_out = (char *)malloc(sizeof(char));

		scanf("%s%s%s", info.id, info.sign_in, info.sign_out);
		stu[i] = info;
	}

	if (n == 1) {
		printf("%s %s", stu[0].id, stu[0].id);
		return 0;
	}
	char *mint = stu[0].sign_in, *maxt = stu[0].sign_out;
	for (i = 1; i < n; i++) {
		if (strcmp(mint, stu[i].sign_in) == 1) {
			min = i;
		}
		if (strcmp(maxt, stu[i].sign_out) == -1) {
			max = i;
		}
	}

	printf("%s %s", stu[min].id, stu[max].id);
	return 0;
}