#include <string>
#include "StateMachine.h"


/*
	�Լ� �̸� : StateMachine::run()
	���	  : STATE_END ���°� �� ������ event-action ���̺� ���ǵ� ��Ģ�� ����ڿ� ���� �߻��Ǵ� �̺�Ʈ�� ���� state machine�� ���۽�Ŵ
	���� ���� : ����
	��ȯ��    : ����
*/
void StateMachine::run()
{
	int i, j;
	Event curEvent;		// ���� �̺�Ʈ

	curState = STATE_READY;				// ���� �ʱ�ȭ
	while (curState != STATE_END)		// EVENT_QUIT�� �Էµ� ������ �ݺ� ������
	{
		curEvent = getNextEvent();		// ���� �̺�Ʈ�� �Է¹���

		for (i = 0; i < NUMBER_OF_TABLE_ENTRIES; i++)   // ���̺� ���ǵ� ����ü ��(transition ����)�� ���� ����
		{
			if (curState == table[i].curState)			// ���� ���¿� ��ġ�ϴ��� �˻�
			{
				if (curEvent == table[i].event)			// �Էµ� ���� �̺�Ʈ�� ��ġ�ϴ��� �˻�
				{
					// �ش� transition�� �߻��� �� �����ؾ� �� action �Լ����� �����Ŵ
					for (j = 0; j < table[i].number_of_actions; j++)
						(this->*table[i].action[j])(table[i].action_parameter[j]);

					curState = table[i].nextState;		// ���̺� ���ǵ� ���� ���·� ���� ���¸� ������
					break;
				}
			}
		}
		cout << endl << endl;
	}
}



/*
	�Լ� �̸� : StateMachine::getNextEvent()
	���	  : ����ڷκ��� ���� �̺�Ʈ�� �Է¹���
	���� ���� : ����
	��ȯ��    : Event -> �Է¹��� �̺�Ʈ ��
*/
Event StateMachine::getNextEvent()
{
	Event selectedEvent;       // ��ȯ�� �̺�Ʈ
	int inputEvent;				// ����ڷκ��� �Է¹��� �̺�Ʈ

	// �Է� �ȳ� �޼��� ���
	cout << "[���� ���� : " << getCurrentStateString() << "]" << endl;
	cout << "1. Deposit a 100 won coin" << endl;
	cout << "2. Press the refund button" << endl;
	cout << "3. Press the beverage button you want" << endl;
	cout << "4. Quit" << endl;
	cout << "Select an event # : ";

	// ����ڷκ��� �̺�Ʈ �Է¹���
	cin >> inputEvent;

	// �Է� ���� ���� ��ȯ�� �̺�Ʈ ���� ������
	switch (inputEvent)
	{
	case 1:
		selectedEvent = EVENT_INSERT_100;
		break;
	case 2:
		selectedEvent = EVENT_REFUND_BUTTON_PRESSED;
		break;
	case 3:
		selectedEvent = EVENT_BEVERAGE_BUTTON_PRESSED;
		break;
	case 4:
	default:
		selectedEvent = EVENT_QUIT;
		curState = STATE_END;
	}

	return selectedEvent;
}



/*
	�Լ� �̸� : StateMachine::displayInsertedMoney()
	���	  : LED ȭ�鿡 ���� ���Ե� �ݾ��� ǥ����
	���� ���� : displayedMoneyAmount -> ȭ�鿡 ��µ� �ݾ�
	��ȯ��    : ����
*/
void StateMachine::displayInsertedMoney(int displayedMoneyAmount)
{
	cout << "���� ���Ե� �ݾ��� " << displayedMoneyAmount << "���Դϴ�." << endl;
}



/*
	�Լ� �̸� : StateMachine::refundCoins()
	���	  : ��ȯ ��ư�� ������ �� ���Ե� �ݾ��� ��ȯ��
	���� ���� : refundedMoneyAmount -> ��ȯ�� �ݾ�
	��ȯ��    : ����
*/
void StateMachine::refundCoins(int refundedMoneyAmount)
{
	cout << "��ȯ�Ǵ� �ݾ��� " << refundedMoneyAmount << "���Դϴ�." << endl;
}



/*
	�Լ� �̸� : StateMachine::turnLight()
	���	  : ���� ��ư�� ������ �Ѱų� ���� ���� ������.
	���� ���� : lightOn -> 1: on, 0: off
	��ȯ��    : ����
*/
void StateMachine::turnLight(int lightOn)
{
	if (lightOn == 1)
		cout << "���� ��ư�� ������ �������ϴ�." << endl;
	else
		cout << "���� ��ư�� ������ �������ϴ�." << endl;
}



/*
	�Լ� �̸� : StateMachine::releaseBeverage()
	���	  : ������ ���Ḧ �ܺη� ������.
	���� ���� : �Ű������� �ʿ� ������ �ٸ� �Լ��� �Ű������� ���߱� ���� �����ϰ� ���ǵ�(dummy parameter)
	��ȯ��    : ����
*/
void StateMachine::releaseBeverage(int dummy)
{
	cout << "���ᰡ ���Խ��ϴ�." << endl;
}


/*
	�Լ� �̸� : StateMachine::getCurrentStateString()
	���	  : ���� ���¿� �ش��ϴ� ��¿� ���ڿ��� �����ؼ� ��ȯ��
	���� ���� : ����
	��ȯ��    : string -> ��¿� ���� ���ڿ�
*/
string StateMachine::getCurrentStateString()
{
	string returnedString;

	switch (curState)
	{
	case STATE_READY:
		returnedString = "STATE_READY";
		break;
	case STATE_100_INSERTED:
		returnedString = "STATE_100_INSERTED";
		break;
	case STATE_200_INSERTED:
		returnedString = "STATE_200_INSERTED";
	}

	return returnedString;
}
