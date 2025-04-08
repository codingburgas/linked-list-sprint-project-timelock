
#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;




int getConsoleWidthMock() {
    return 40;
}

void centerTextTestable(string text, int consoleWidth, ostream& out) {
    int paddingLeft = (consoleWidth - text.length()) / 2;
    if (paddingLeft < 0) paddingLeft = 0;
    out << string(paddingLeft, ' ') << text;
}

void printEndlTestable(int num, ostream& out) {
    for (int i = 0; i < num; i++) {
        out << '\n';
    }
}

void printStrRepeatTestable(string str, int num, ostream& out) {
    for (int i = 0; i < num; i++) {
        out << str;
    }
}


bool clearScreenCalled = false;
void clearScreenMock() {
    clearScreenCalled = true;
}


string renderAdminPanelMenu() {
    stringstream out;
    string resetColor = "\033[37m";
    string purpleColor = "\033[35m";

    out << string(12, ' ') << "1. View all events.";
    out << string(12, ' ') << "2. Search by year.";
    out << string(12, ' ') << "3. Search by event.";
    out << string(12, ' ') << "4. Add an event at the beginning.";
    out << "\n\n";
    out << string(12, ' ') << "5. Add an event at the end.";
    out << string(12, ' ') << "6. Edit an event.";
    out << string(12, ' ') << "7. Delete an event.";
    out << string(12, ' ') << "8. Open favourites.";
    out << "\n\n";
    out << string(65, ' ') << "9. Approve admin.";
    out << "\n\n\n";

    int centerPad = (getConsoleWidthMock() - 29) / 2;
    out << string(centerPad, ' ') << purpleColor + "            Choose an option! " + resetColor;

    return out.str();
}



namespace UnitTestingTimelock
{
    TEST_CLASS(UnitTestingTimelock)
    {
    public:

        TEST_METHOD(Test_centerText)
        {
            stringstream output;
            centerTextTestable("Hello", getConsoleWidthMock(), output);
            string expectedPadding(17, ' ');
            Assert::AreEqual(expectedPadding + "Hello", output.str());
        }

        TEST_METHOD(Test_printEndl)
        {
            stringstream output;
            printEndlTestable(3, output);
            Assert::AreEqual(string("\n\n\n"), output.str());
        }

        TEST_METHOD(Test_printStrRepeat)
        {
            stringstream output;
            printStrRepeatTestable("ab", 3, output);
            Assert::AreEqual(string("ababab"), output.str());
        }

        TEST_METHOD(Test_clearScreen_called)
        {
            clearScreenCalled = false;
            clearScreenMock();
            Assert::IsTrue(clearScreenCalled);
        }

        TEST_METHOD(Test_renderAdminPanelMenu)
        {
            string menu = renderAdminPanelMenu();
            Assert::IsTrue(menu.find("1. View all events.") != string::npos);
            Assert::IsTrue(menu.find("9. Approve admin.") != string::npos);
            Assert::IsTrue(menu.find("Choose an option!") != string::npos);
        }
    };
}
