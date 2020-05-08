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
	}//poly�迭�� �� �ε������� ����Ǿ��ֳ� �˻� �ִ� �ε����� max
	tempc = poly[max].GetCoefficient();//�ִ� �ε��� ���
	tempe = poly[max].GetExponent();//�ִ� �ε��� ����
	cout << tempc << "x^" << tempe;//�ִ� �ε��� ���
	for (i = max - 1; i >= 0; i--) {//�ְ��׺��� �Ųٷ� ���
		tempc = poly[i].GetCoefficient();
		tempe = poly[i].GetExponent();
		if (tempc > 0) {
			cout << " + " << tempc << "x^" << tempe;//����� ����� +������ ���
		}
		else {
			cout << tempc << "x^" << tempe;//����� ������ �׳� ���
		}
	}
	cout << "\n";
}

Term& AddOnePrefix(Term& Operand) {//����ó��
	++Operand.coefficient;
	return Operand;
}

Term AddOnePostfix(Term& Operand) {//����ó��
	Term temp;
	temp = Operand;
	++Operand.coefficient;
	return temp;
}

Term& MinusOnePrefix(Term& Operand) {//����ó��
	--Operand.coefficient;
	return Operand;
}

Term MinusOnePostfix(Term& Operand) {//����ó��
	Term temp;
	temp = Operand;
	--Operand.coefficient;
	return Operand;
}

Term Term::operator-() const {//��ȣ�ٲٱ�
	Term res;
	res.coefficient = -coefficient;
	res.exponent = exponent;
	return res;
}

Polynomial Polynomial::operator+(Polynomial rightHand) {//���׽ĳ��� + ����
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
		time++;//������ ���� ���� ���׽� ���� ����� ����
	}
	for (i = 1; i < rightHand.poly[i].GetCoefficient() != '\0'; i++) {
		time2++;//������ ���� ������ ���׽� ���� ����� ����
	}
	for (i = 0; i <= time; i++) {
		flag = 0;
		for (j = 0; j <= time2; j++) {
			if (this->poly[i].GetExponent() == rightHand.poly[j].GetExponent()) {//���� ���׽İ� ������ ���׽� ������ ������ ���ؼ� ���ο� Ŭ������ ����
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
			if (rightHand.poly[i].GetExponent() == this->poly[j].GetExponent()) {//������ ���׽Ŀ��� �ִµ� ���� ���׽Ŀ��� ���� ������ ���ο� Ŭ������ ����
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
	assignment(&res);//�� ���׽� ������ ���׽� ����


	return res;
}

Polynomial Polynomial::operator-(Polynomial rightHand) {//���׽ĳ��� - ����
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
		time++;//������ ���� ���� ���׽� ���� ����� ����
	}
	for (i = 1; i < rightHand.poly[i].GetCoefficient() != '\0'; i++) {
		time2++;//������ ���� ������ ���׽� ���� ����� ����
	}
	for (i = 0; i <= time2; i++) {
		tempc = -rightHand.poly[i].GetCoefficient();
		rightHand.poly[i].SetCoefficient(tempc);
	}//������ ���� ������ ���׽� ��ȣ �ٲ��ֱ�
	for (i = 0; i <= time; i++) {
		flag = 0;
		for (j = 0; j <= time2; j++) {
			if (this->poly[i].GetExponent() == rightHand.poly[j].GetExponent()) {//���� ���׽İ� ������ ���׽� ������ ������ ���ؼ� ���ο� Ŭ������ ����
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
			if (rightHand.poly[i].GetExponent() == this->poly[j].GetExponent()) {//������ ���׽Ŀ��� �ִµ� ���� ���׽Ŀ��� ���� ������ ���ο� Ŭ������ ����
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
	assignment(&res);//�� ���׽� ������ ���׽� ����


	return res;
}

void Polynomial::assignment(Polynomial* N) {//���׽� ���� �迭 ���� ������������ ����
	Term temp;
	int min;
	int idx = 0;

	for (int i = 0; i < N->cnt; i++) {//��������
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
	if (cnt == 0) {//ó���޴� ���̸� �׳� �ޱ�
		poly[cnt].SetExponent(e);
		poly[cnt].SetCoefficient(c);
		cnt++;
	}
	else {
		for (int i = 0; i < cnt; i++) {
			if (poly[i].GetExponent() == e) {//�ִ� ������ ��� ���ϱ�
				poly[i].SetCoefficient((poly[i].GetCoefficient() + c));
				flag = 1;
				break;
			}
		}
		if (!flag) {//���� ������ �׳� �ޱ�
			poly[cnt].SetExponent(e);
			poly[cnt].SetCoefficient(c);
			cnt++;
		}
	}

	assignment(this);//�ް��� ����

	return;
}
