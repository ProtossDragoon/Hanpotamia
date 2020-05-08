#include "midterm.h"

Term::Term(int c, int e) : coefficient(c), exponent(e)
{
}

void Polynomial::ShowPoly() const {
	int i;
	int max = 0;
	int tempc, tempe;
	for (i = 0; poly[i].GetCoefficient() != '\0'; i++) {
		max = i;
	}//poly배열에 몇 인덱스까지 저장되어있나 검사 최대 인덱스가 max
	tempc = poly[max].GetCoefficient();//최대 인덱스 계수
	tempe = poly[max].GetExponent();//최대 인덱스 지수
	cout << tempc << "x^" << tempe;//최대 인덱스 출력
	for (i = max - 1; i >= 0; i--) {//최고항부터 거꾸로 출력
		tempc = poly[i].GetCoefficient();
		tempe = poly[i].GetExponent();
		if (tempc > 0) {
			cout << " + " << tempc << "x^" << tempe;//계수가 양수면 +붙혀서 출력
		}
		else {
			cout << tempc << "x^" << tempe;//계수가 음수면 그냥 출력
		}
	}
	cout << "\n";
}

Term& AddOnePrefix(Term& Operand) {//선행처리
	++Operand.coefficient;
	return Operand;
}

Term AddOnePostfix(Term& Operand) {//후행처리
	Term temp;
	temp = Operand;
	++Operand.coefficient;
	return temp;
}

Term& MinusOnePrefix(Term& Operand) {//선행처리
	--Operand.coefficient;
	return Operand;
}

Term MinusOnePostfix(Term& Operand) {//후행처리
	Term temp;
	temp = Operand;
	--Operand.coefficient;
	return Operand;
}

Term Term::operator-() const {//부호바꾸기
	Term res;
	res.coefficient = -coefficient;
	res.exponent = exponent;
	return res;
}

Polynomial Polynomial::operator+(Polynomial rightHand) {//다항식끼리 + 연산
	Polynomial res;
	Polynomial* temp;
	int i;
	int j;
	int count = 0;
	int time = 0;
	int time2 = 0;
	int flag = 0;
	int tempc, tempe;
	for (i = 1; this->poly[i].GetCoefficient() != '\0'; i++) {
		time++;//연산자 기준 왼쪽 다항식 항이 몇개인지 세기
	}
	for (i = 1; i < rightHand.poly[i].GetCoefficient() != '\0'; i++) {
		time2++;//연산자 기준 오른쪽 다항식 항이 몇개인지 세기
	}
	for (i = 0; i <= time; i++) {
		flag = 0;
		for (j = 0; j <= time2; j++) {
			if (this->poly[i].GetExponent() == rightHand.poly[j].GetExponent()) {//왼쪽 다항식과 오른쪽 다항식 지수가 같으면 더해서 새로운 클래스에 넣음
				flag = 1;
				tempc = this->poly[i].GetCoefficient() + rightHand.poly[j].GetCoefficient();
				tempe = poly[i].GetExponent();
			}
			if (!flag) {
				tempc = this->poly[i].GetCoefficient();
				tempe = this->poly[i].GetExponent();
			}
		}
		res.poly[res.cnt].SetCoefficient(tempc);
		res.poly[res.cnt].SetExponent(tempe);
		res.cnt++;
	}
	for (i = 0; i <= time2; i++) {
		flag = 0;
		for (j = 0; j < time; j++) {
			if (rightHand.poly[i].GetExponent() == this->poly[j].GetExponent()) {//오른쪽 다항식에는 있는데 왼쪽 다항식에는 없는 지수면 새로운 클래스에 넣음
				flag = 1;
			}
		}
		if (!flag) {
			tempc = rightHand.poly[i].GetCoefficient();
			tempe = rightHand.poly[i].GetExponent();
			res.poly[res.cnt].SetCoefficient(tempc);
			res.poly[res.cnt].SetExponent(tempe);
			res.cnt++;
		}
	}

	temp = &res;
	assignment(&res);//두 다항식 합쳐진 다항식 정렬


	return res;
}

Polynomial Polynomial::operator-(Polynomial rightHand) {//다항식끼리 - 연산
	Polynomial res;
	Polynomial* temp;
	int i;
	int j;
	int count = 0;
	int time = 0;
	int time2 = 0;
	int flag = 0;
	int tempc, tempe;
	for (i = 1; this->poly[i].GetCoefficient() != '\0'; i++) {
		time++;//연산자 기준 왼쪽 다항식 항이 몇개인지 세기
	}
	for (i = 1; i < rightHand.poly[i].GetCoefficient() != '\0'; i++) {
		time2++;//연산자 기준 오른쪽 다항식 항이 몇개인지 세기
	}
	for (i = 0; i <= time2; i++) {
		tempc = -rightHand.poly[i].GetCoefficient();
		rightHand.poly[i].SetCoefficient(tempc);
	}//연산자 기준 오른쪽 다항식 부호 바꿔주기
	for (i = 0; i <= time; i++) {
		flag = 0;
		for (j = 0; j <= time2; j++) {
			if (this->poly[i].GetExponent() == rightHand.poly[j].GetExponent()) {//왼쪽 다항식과 오른쪽 다항식 지수가 같으면 더해서 새로운 클래스에 넣음
				flag = 1;
				tempc = this->poly[i].GetCoefficient() + rightHand.poly[j].GetCoefficient();
				tempe = poly[i].GetExponent();
			}
			if (!flag) {
				tempc = this->poly[i].GetCoefficient();
				tempe = this->poly[i].GetExponent();
			}
		}
		res.poly[res.cnt].SetCoefficient(tempc);
		res.poly[res.cnt].SetExponent(tempe);
		res.cnt++;
	}
	for (i = 0; i <= time2; i++) {
		flag = 0;
		for (j = 0; j < time; j++) {
			if (rightHand.poly[i].GetExponent() == this->poly[j].GetExponent()) {//오른쪽 다항식에는 있는데 왼쪽 다항식에는 없는 지수면 새로운 클래스에 넣음
				flag = 1;
			}
		}
		if (!flag) {
			tempc = rightHand.poly[i].GetCoefficient();
			tempe = rightHand.poly[i].GetExponent();
			res.poly[res.cnt].SetCoefficient(tempc);
			res.poly[res.cnt].SetExponent(tempe);
			res.cnt++;
		}
	}

	temp = &res;
	assignment(&res);//두 다항식 합쳐진 다항식 정렬


	return res;
}

void Polynomial::assignment(Polynomial* N) {//다항식 받은 배열 지수 오름차순으로 정렬
	Term temp;
	int min;
	int idx = 0;

	for (int i = 0; i < N->cnt; i++) {//선택정렬
		min = i;
		for (int j = i + 1; j < N->cnt; j++) {
			if (N->poly[j].GetExponent() < N->poly[min].GetExponent()) {
				min = j;
			}
		}

		temp = N->poly[i];
		N->poly[i] = N->poly[min];
		N->poly[min] = temp;
	}


}

void Polynomial::SetTerm(int c, int e) {//Term setting
	int flag = 0;
	if (cnt == 0) {//처음받는 항이면 그냥 받기
		poly[cnt].SetExponent(e);
		poly[cnt].SetCoefficient(c);
		cnt++;
	}
	else {
		for (int i = 0; i < cnt; i++) {
			if (poly[i].GetExponent() == e) {//있는 지수면 계수 더하기
				poly[i].SetCoefficient((poly[i].GetCoefficient() + c));
				flag = 1;
				break;
			}
		}
		if (!flag) {//없는 지수면 그냥 받기
			poly[cnt].SetExponent(e);
			poly[cnt].SetCoefficient(c);
			cnt++;
		}
	}

	assignment(this);//받고나서 정렬

	return;
}
