#include <bits/stdc++.h>
using namespace std;

const int N = (1<<17);
struct Node;
Node* empty;

struct Node{
	int sum;
	Node * lft, * rit;
	Node(){lft = rit = this; sum = 0;}
	Node(int s, Node* l = empty, Node* r = empty){
		lft = l;
		rit = r;
		sum = s;
	}
};

Node* insert(Node* cur, int ns, int ne, int val){
	if(val < ns || val > ne)	return cur;
	if(ns==ne)	return new Node(cur->sum+1);
	int med = ns+((ne-ns)>>1);
	Node* lf = insert(cur->lft, ns, med, val);
	Node* rt = insert(cur->rit, med+1, ne, val);
	return new Node(lf->sum+rt->sum, lf, rt);
}

int query(Node* e, Node* s, int k, int ns, int ne){
	if(ns == ne)	return ns;
	int lsz = e->lft->sum - s->lft->sum;
	int med = ns+((ne-ns)>>1);
	if(k<=lsz)
		return query(e->lft, s->lft, k, ns, med);
	return query(e->rit, s->rit, k-lsz, med+1, ne);
}

Node* roots[N];
int m, x, q, l, r, k;

int main() {
	empty = new Node;
	roots[0] = empty;
	scanf("%d %d", &m, &q);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d", &x);
		roots[i] = insert(roots[i-1], -1e9, 1e9, x);
	}
	while(q--){
		scanf("%d %d %d", &l, &r, &k);
		printf("%d\n", query(roots[r], roots[l-1], k, -1e9, 1e9));
	}
  return 0;
}
