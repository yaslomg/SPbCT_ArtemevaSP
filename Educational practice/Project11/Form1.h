#include <ctime>
#include <fstream>
#include <Windows.h>
#include <string>
#include "VectorLibrary.h"
#pragma warning(disable : 4996)
using namespace std;
using namespace VectorFuns;
Vector vect[10];

HANDLE out;
HANDLE hSemaphore;
HANDLE hThread;

DWORD WINAPI Sort(LPVOID N) {
	char buff[11];
	for (int i = 0; i < 10; i++) {
		for (int j = (10 - 1); j >= (i + 1); j--) {
			if (vect[(int)N].show(j) < vect[(int)N].show(j - 1)) {
				vect[(int)N].swap(j, j - 1);
			}
		}
	}
	for (int i = 0; i < 10; i++)
		buff[i] = vect[(int)N].show(i);
	buff[10] = '\n';
	WriteFile(out, buff, 11, NULL, NULL);
	ReleaseSemaphore(hSemaphore, 1, NULL);
	return 0;
}

namespace Form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

		}

	protected:

		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;



	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button3;






	private:

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(37, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(333, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ФИО: Артемьева София Павловна";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(555, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(115, 20);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Группа: 500";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(37, 59);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Дата:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(244, 59);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Время: ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(376, 407);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(312, 52);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Отсортировать данные по возрастанию и сохранить результат в файл";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(41, 407);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(162, 52);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Загрузить данные из исходного файла";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->GridColor = System::Drawing::Color::DeepSkyBlue;
			this->dataGridView1->Location = System::Drawing::Point(41, 106);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(647, 227);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellContentClick);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(38, 367);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 17);
			this->label5->TabIndex = 4;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(373, 367);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 17);
			this->label6->TabIndex = 5;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(376, 479);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(312, 28);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Сделать файл только для чтения";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(739, 533);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		time_t now = time(0);
		tm* date_time = localtime(&now);
		label3->Text += "      " + date_time->tm_mday + "." + (1 + date_time->tm_mon) + "." + (date_time->tm_year + 1900);
		label4->Text += "   " + date_time->tm_hour + ":" + date_time->tm_min + ":" + date_time->tm_sec;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ifstream in("input.txt");
		dataGridView1->ColumnCount = 10;
		dataGridView1->RowCount = 10;
		if (in.is_open()) {
			char ch;
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					in.get(ch);
					vect[i].push_back(ch);
					dataGridView1->Rows[i]->Cells[j]->Value = ((wchar_t)ch).ToString();
				}
			}
			
			in.close();
		}
		else {
			label5->Text = "Ошибка! Не удалось открыть файл";
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		out = CreateFile(L"output.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_READONLY, NULL);
		if (out == INVALID_HANDLE_VALUE)
			label6->Text = "Не удалось создать файл";
		else {
			hSemaphore = CreateSemaphore(NULL, 0, 10, NULL);
			for (int i = 0; i < 10; i++) {
				hThread = CreateThread(NULL, 0, Sort, (LPVOID)i, 0, NULL);
				WaitForSingleObject(hSemaphore, INFINITE);
			}
			dataGridView1->ColumnCount = 10;
			dataGridView1->RowCount = 10;
			char ch;
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					dataGridView1->Rows[i]->Cells[j]->Value = ((wchar_t)vect[i].show(j)).ToString();
				}
			}
			CloseHandle(out);
			SetFileAttributesA("output.txt", FILE_ATTRIBUTE_NORMAL);

		}
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		LPSTR lpFileName = "output.txt";
		SetFileAttributesA(lpFileName, FILE_ATTRIBUTE_READONLY);
	}
};
}