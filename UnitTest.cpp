#include "pch.h"
#include "CppUnitTest.h"
#include "../queue/priority_queue.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace quetest
{
	TEST_CLASS(quetest)
	{
	public:

		TEST_METHOD(Test_Get_first)
		{
			//1
			priority_queue<int> a;

			a.push(1, 1);
			a.push(2, 1);
			a.push(3, 1);
			a.push(4, 2);
			a.push(10, 1);

			int r1, a1 = 1;

			r1 = a.get_first();
			Assert::AreEqual(a1, r1);

			//2
			priority_queue<int> b;

			b.push(10, 1);
			b.push(20, 2);
			b.push(30, 3);

			int r2, a2 = 10;

			r2 = b.get_first();
			Assert::AreEqual(a2, r2);

			//3
			priority_queue<int> c;

			c.push(5, 1);
			c.push(6, 1);
			c.push(9, 1);

			int r3, a3 = 5;

			r3 = c.get_first();
			Assert::AreEqual(a3, r3);
		}

		TEST_METHOD(Test_top)
		{
			//1
			priority_queue<int> a;

			a.push(1, 2);
			a.push(2, 1);
			a.push(3, 1);
			a.push(4, 2);
			a.push(10, 1);

			int r1, a1 = 2;

			r1 = a.top();
			Assert::AreEqual(a1, r1);

			//2

			priority_queue<int> b;

			b.push(10, 1);
			b.push(20, 2);
			b.push(30, 3);

			int r2, a2 = 10;
			r2 = b.top();
			Assert::AreEqual(a2, r2);

			//3
			priority_queue<int> c;

			c.push(5, 1);
			c.push(6, 1);
			c.push(9, 1);

			int r3, a3 = 5;

			r3 = c.top();
			Assert::AreEqual(a3, r3);
		}

		TEST_METHOD(Test_oper_combo)
		{

			priority_queue<int> a;
			priority_queue<int> b;

			a.push(3, 1);
			a.push(6, 2);
			a.push(2, 1);

			b.push(4, 1);
			b.push(6, 3);
			b.push(3, 2);

			priority_queue<int> f;
			f = (a + b);

			//1
			priority_queue<int> g;
			g.push(3, 1);
			g.push(6, 2);
			g.push(2, 1);
			g.push(4, 1);
			g.push(6, 3);
			g.push(3, 2);

			Assert::IsTrue(g == f);

			//2
			priority_queue<int> t;
			t.push(3, 1);
			t.push(6, 2);
			t.push(2, 1);

			t.push(4, 1);
			t.push(6, 3);
			t.push(33, 2);
			Assert::IsFalse(g == t);
		}

		TEST_METHOD(Test_is_empty)
		{
			//1
			priority_queue<int> a;

			a.push(1, 1);
			a.push(2, 1);

			bool f1 = 0;

			Assert::AreEqual(f1, a.isEmpty());

			//2
			priority_queue<int> b;
			bool f2 = 1;

			Assert::AreEqual(f2, b.isEmpty());
		}
	};
}
