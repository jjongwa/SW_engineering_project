#include <iostream>

#define NUMBER_OF_TABLE_ENTRIES 100     // event-action table�� ���� entry ����
#define MAX_NUMBER_OF_ACTIONS   3       // transition �� ����Ǵ� �ִ� action ����

using namespace std;


// State ������ ����
typedef enum {
    STATE_READY,
    STATE_100_INSERTED,
    STATE_200_INSERTED,
    STATE_END
} State;


// Event ������ ����
typedef enum {
    EVENT_INSERT_100,
    EVENT_REFUND_BUTTON_PRESSED,
    EVENT_BEVERAGE_BUTTON_PRESSED,
    EVENT_QUIT
} Event;


// ���� �ڵ��Ǹű⸦ ���� StateMachine Ŭ���� ����
class StateMachine
{
private:
    State curState;     // ���� ����

    // event-action table structure ����
    typedef struct {
        State curState;             // ���� ����
        Event event;                // ����ڷκ��� �߻��� �̺�Ʈ
        int number_of_actions;                                      // �ش� transition�� ����Ǵ� action �Լ��� ����
        void (StateMachine::* action[MAX_NUMBER_OF_ACTIONS])(int);   // action �Լ� �������� �迭
        int action_parameter[MAX_NUMBER_OF_ACTIONS];                 // action �Լ��� �Ű����� �迭
        State nextState;            // transition �Ŀ� ����� ���� ����
    } EventActionTable;
    // vending machine���� ����� event-action table �ʱ�ȭ
    EventActionTable table[NUMBER_OF_TABLE_ENTRIES]{
        {STATE_READY,	        EVENT_INSERT_100,	           1,  {&StateMachine::displayInsertedMoney},	                                                        {100},       STATE_100_INSERTED},
        {STATE_100_INSERTED,	EVENT_INSERT_100,	           2,  {&StateMachine::displayInsertedMoney, &StateMachine::turnLight},	                                {200, 1},    STATE_200_INSERTED},
        {STATE_100_INSERTED,	EVENT_REFUND_BUTTON_PRESSED,   2,  {&StateMachine::displayInsertedMoney, &StateMachine::refundCoins},	                            {0, 100},    STATE_READY},
        {STATE_200_INSERTED,	EVENT_INSERT_100,	           1,  {&StateMachine::refundCoins},	                                                                {100},       STATE_200_INSERTED},
        {STATE_200_INSERTED,	EVENT_REFUND_BUTTON_PRESSED,   3,  {&StateMachine::displayInsertedMoney, &StateMachine::refundCoins, &StateMachine::turnLight},	    {0, 200, 0}, STATE_READY},
        {STATE_200_INSERTED,	EVENT_BEVERAGE_BUTTON_PRESSED, 3,  {&StateMachine::displayInsertedMoney, &StateMachine::turnLight, &StateMachine::releaseBeverage}, {0, 0, 0},   STATE_READY}
    };

    void displayInsertedMoney(int displayedMoneyAmount); // LED ȭ�鿡 ���� ���Ե� �ݾ��� ǥ����
    void refundCoins(int refundedMoneyAmount);           // ��ȯ ��ư�� ������ �� ���Ե� �ݾ��� ��ȯ��
    void turnLight(int lightOn);                         // ���� ��ư�� ������ �Ѱų� ���� ���� ������.  ->  on = 1,  off = 0;
    void releaseBeverage(int dummy);                     // ������ ���Ḧ �ܺη� ������ -> dummy parameter

    Event getNextEvent();       // ����ڷκ��� ���� �̺�Ʈ�� �Է¹���

    string getCurrentStateString();     // ���� ���¿� �ش��ϴ� ���ڿ��� �����ؼ� ��ȯ��


public:
    void run();               // state machine ���� 
};

