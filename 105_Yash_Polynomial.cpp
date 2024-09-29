#include <iostream>
using namespace std;

struct term {
  int coeff, power;
  term *next;
};

class polynomial {
public:
  term *head = nullptr;
  void initTerm(int, int);
  void displayPoly();
  polynomial operator+(polynomial p) {
    term *e1 = head;
    term *e2 = p.head;
    polynomial p3;
    while (e1 && e2) {
      if (e1->power == e2->power) {
        p3.initTerm((e1->coeff + e2->coeff), e1->power);
        e1 = e1->next;
        e2 = e2->next;
      } else if (e1->power > e2->power) {
        p3.initTerm(e1->coeff, e1->power);
        e1 = e1->next;
      } else {
        p3.initTerm(e2->coeff, e2->power);
        e2 = e2->next;
      }
    }
    while (e1) {
      p3.initTerm(e1->coeff, e1->power);
      e1 = e1->next;
    }
    while (e2) {
      p3.initTerm(e2->coeff, e2->power);
      e2 = e2->next;
    }
    return p3;
  }
};

void polynomial ::initTerm(int c, int p) {
  term *nt = new term;
  nt->coeff = c;
  nt->power = p;
  nt->next = nullptr;
  if (!head) {
    head = nt;
    return;
  }
  term *trav = head;
  if (trav->power < nt->power) {
    nt->next = trav;
    head = nt;
    return;
  }
  while (trav->next && trav->next->power >= nt->power) {
    trav = trav->next;
  }
  if (trav->power == nt->power) {
    trav->coeff = trav->coeff + nt->coeff;
    delete nt;
    return;
  }
  nt->next = trav->next;
  trav->next = nt;
}

void polynomial ::displayPoly() {
  term *trav = head;
  if (!trav) {
    cout << "$ the polynomial is empty" << endl;
    return;
  }
  while (trav) {
    string sign = trav->coeff < 0 ? "-" : "+";
    if (trav == head && trav->coeff >= 0) {
      cout << endl;
      sign = "$";
    }
    if (trav == head && trav->coeff < 0) {
      cout << endl;
      sign = "$ -";
    }
    cout << sign << " " << abs(trav->coeff) << "x^" << trav->power << " ";
    trav = trav->next;
  }
  cout << endl;
}

int main() {
  polynomial p1, p2, p3;

  p1.initTerm(12, 3);
  p1.initTerm(1, 4);
  p1.initTerm(4, 3);
  p1.initTerm(2, 6);
  p1.initTerm(-4, 3);
  p1.initTerm(10, 7);
  p1.initTerm(-10, 5);
  p1.displayPoly();

  p2.initTerm(42, 1);
  p2.initTerm(18, 4);
  p2.initTerm(5, 4);
  p2.initTerm(-22, 6);
  p2.initTerm(7, 2);
  p2.initTerm(1, 5);
  p2.initTerm(11, 5);
  p2.displayPoly();

  p3 = p1 + p2;
  p3.displayPoly();
  cout << endl;
  return 0;
}
