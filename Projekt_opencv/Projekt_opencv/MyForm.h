#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string> 
#include <ctime>
#include "msclr\marshal_cppstd.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <msclr\marshal_cppstd.h>
#include <algorithm>
#include <chrono>
#include <time.h>
#include <iomanip>
namespace Projektopencv {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	using namespace cv;
	using namespace std;

	double dWidth = 0;
	double dHeight = 0;
	bool framesCheck = false;
	bool framesTosave = false;
	int imagesToRecord = 99999;
	int imageIndex = 0;
	int videoIndex = 0;
	int choice = 0;
	int mouseX = 0;
	int mouseY = 0;
	int delay = 24 * 5;
	VideoCapture cap;
	VideoWriter oVideoWriter;
	Mat frame2, original;
	Mat frame, frame_gray;
	vector<Rect> faces;
	string videoPathStr;
	string imagePathStr ="";
	boolean useImage = false;
	string destinationPath;
	string face_cascade_path = "C:\\Users\\Ukleja\\Desktop\\Opencv\\Projekt_opencv\\haarcascade_frontalface_alt.xml";
	string eyes_cascade_path = "C:\\Users\\Ukleja\\Desktop\\Opencv\\Projekt_opencv\\haarcascade_eye_tree_eyeglasses.xml";
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	chrono::steady_clock sc;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			if (!face_cascade.load(face_cascade_path)) {
				cout << ("--(!)Error loading\n");
			};
			if (!eyes_cascade.load(eyes_cascade_path)) {
				cout << ("--(!)Error loading\n");
			};
			cout << ("Loaded succesfully\n");

		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  imageWindow;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  cameraButton;
	private: System::Windows::Forms::Button^  BlurButton;
	private: System::Windows::Forms::Button^  BlackLineButton;
	private: System::Windows::Forms::Button^  CopyFaceButton;

	private: System::Windows::Forms::Button^  PinkCircleButton;
	private: System::Windows::Forms::TextBox^  framesTosaveText;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  videoPath;
	private: System::Windows::Forms::Button^  selectDestinationButton;

	private: System::Windows::Forms::Label^  saveRecordLabel;
	private: System::Windows::Forms::RadioButton^  PlayVideoRadioButton;
	private: System::Windows::Forms::RadioButton^  PlayCameraRadioButton;

	private: System::Windows::Forms::Button^  startRecordingButton;
	private: System::Windows::Forms::RadioButton^  RecordVideoRadioButton;
	private: System::Windows::Forms::RadioButton^  RecordImagesRadioButton;

	private: System::Windows::Forms::CheckBox^  framesCheckBox;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  saveImageButton;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  imageToReplaceButton;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  imagePath;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  motionDetectorButton;


	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->imageWindow = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->cameraButton = (gcnew System::Windows::Forms::Button());
			this->BlurButton = (gcnew System::Windows::Forms::Button());
			this->BlackLineButton = (gcnew System::Windows::Forms::Button());
			this->CopyFaceButton = (gcnew System::Windows::Forms::Button());
			this->PinkCircleButton = (gcnew System::Windows::Forms::Button());
			this->framesTosaveText = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->videoPath = (gcnew System::Windows::Forms::Label());
			this->selectDestinationButton = (gcnew System::Windows::Forms::Button());
			this->saveRecordLabel = (gcnew System::Windows::Forms::Label());
			this->PlayVideoRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->PlayCameraRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->startRecordingButton = (gcnew System::Windows::Forms::Button());
			this->RecordVideoRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->RecordImagesRadioButton = (gcnew System::Windows::Forms::RadioButton());
			this->framesCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->imagePath = (gcnew System::Windows::Forms::Label());
			this->imageToReplaceButton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->saveImageButton = (gcnew System::Windows::Forms::Button());
			this->motionDetectorButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageWindow))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(7, 20);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(281, 39);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Select source file";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// imageWindow
			// 
			this->imageWindow->BackColor = System::Drawing::Color::Black;
			this->imageWindow->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imageWindow.ErrorImage")));
			this->imageWindow->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imageWindow.Image")));
			this->imageWindow->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imageWindow.InitialImage")));
			this->imageWindow->Location = System::Drawing::Point(80, 77);
			this->imageWindow->Name = L"imageWindow";
			this->imageWindow->Size = System::Drawing::Size(771, 476);
			this->imageWindow->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->imageWindow->TabIndex = 1;
			this->imageWindow->TabStop = false;
			this->imageWindow->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pb_MouseDown);
			// 
			// timer1
			// 
			this->timer1->Interval = 40;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// cameraButton
			// 
			this->cameraButton->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->cameraButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cameraButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cameraButton->Location = System::Drawing::Point(632, 3);
			this->cameraButton->Name = L"cameraButton";
			this->cameraButton->Size = System::Drawing::Size(134, 60);
			this->cameraButton->TabIndex = 2;
			this->cameraButton->Text = L"Run camera";
			this->cameraButton->UseVisualStyleBackColor = false;
			this->cameraButton->Click += gcnew System::EventHandler(this, &MyForm::cameraButton_Click);
			// 
			// BlurButton
			// 
			this->BlurButton->BackColor = System::Drawing::SystemColors::Control;
			this->BlurButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BlurButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->BlurButton->Location = System::Drawing::Point(857, 77);
			this->BlurButton->Name = L"BlurButton";
			this->BlurButton->Size = System::Drawing::Size(67, 151);
			this->BlurButton->TabIndex = 3;
			this->BlurButton->Text = L"Blur";
			this->BlurButton->UseVisualStyleBackColor = false;
			this->BlurButton->Click += gcnew System::EventHandler(this, &MyForm::Blur_Click);
			// 
			// BlackLineButton
			// 
			this->BlackLineButton->BackColor = System::Drawing::SystemColors::Control;
			this->BlackLineButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->BlackLineButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->BlackLineButton->Location = System::Drawing::Point(857, 234);
			this->BlackLineButton->Name = L"BlackLineButton";
			this->BlackLineButton->Size = System::Drawing::Size(67, 170);
			this->BlackLineButton->TabIndex = 4;
			this->BlackLineButton->Text = L"Black line";
			this->BlackLineButton->UseVisualStyleBackColor = false;
			this->BlackLineButton->Click += gcnew System::EventHandler(this, &MyForm::BlackLine_Click);
			// 
			// CopyFaceButton
			// 
			this->CopyFaceButton->BackColor = System::Drawing::SystemColors::Control;
			this->CopyFaceButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->CopyFaceButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->CopyFaceButton->Location = System::Drawing::Point(7, 321);
			this->CopyFaceButton->Name = L"CopyFaceButton";
			this->CopyFaceButton->Size = System::Drawing::Size(67, 232);
			this->CopyFaceButton->TabIndex = 6;
			this->CopyFaceButton->Text = L"Copy face";
			this->CopyFaceButton->UseVisualStyleBackColor = false;
			this->CopyFaceButton->Click += gcnew System::EventHandler(this, &MyForm::CopyFaceButton_Click);
			// 
			// PinkCircleButton
			// 
			this->PinkCircleButton->BackColor = System::Drawing::SystemColors::Control;
			this->PinkCircleButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->PinkCircleButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->PinkCircleButton->Location = System::Drawing::Point(7, 77);
			this->PinkCircleButton->Name = L"PinkCircleButton";
			this->PinkCircleButton->Size = System::Drawing::Size(67, 238);
			this->PinkCircleButton->TabIndex = 5;
			this->PinkCircleButton->Text = L"Pink circle";
			this->PinkCircleButton->UseVisualStyleBackColor = false;
			this->PinkCircleButton->Click += gcnew System::EventHandler(this, &MyForm::PinkCircleButton_Click);
			// 
			// framesTosaveText
			// 
			this->framesTosaveText->Enabled = false;
			this->framesTosaveText->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->framesTosaveText->Location = System::Drawing::Point(396, 41);
			this->framesTosaveText->Name = L"framesTosaveText";
			this->framesTosaveText->Size = System::Drawing::Size(150, 25);
			this->framesTosaveText->TabIndex = 8;
			this->framesTosaveText->Text = L"5";
			this->framesTosaveText->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->framesTosaveText->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Gray;
			this->label1->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(393, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 18);
			this->label1->TabIndex = 9;
			this->label1->Text = L"frames to save";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Gray;
			this->label2->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(4, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 18);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Path:";
			// 
			// videoPath
			// 
			this->videoPath->AutoSize = true;
			this->videoPath->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->videoPath->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->videoPath->Location = System::Drawing::Point(49, 3);
			this->videoPath->Name = L"videoPath";
			this->videoPath->Size = System::Drawing::Size(39, 18);
			this->videoPath->TabIndex = 11;
			this->videoPath->Text = L"Path:";
			this->videoPath->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// selectDestinationButton
			// 
			this->selectDestinationButton->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->selectDestinationButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->selectDestinationButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->selectDestinationButton->Location = System::Drawing::Point(6, 22);
			this->selectDestinationButton->Name = L"selectDestinationButton";
			this->selectDestinationButton->Size = System::Drawing::Size(192, 44);
			this->selectDestinationButton->TabIndex = 12;
			this->selectDestinationButton->Text = L"Select destination folder";
			this->selectDestinationButton->UseVisualStyleBackColor = false;
			this->selectDestinationButton->Click += gcnew System::EventHandler(this, &MyForm::selectDestinationButton_Click);
			// 
			// saveRecordLabel
			// 
			this->saveRecordLabel->AutoSize = true;
			this->saveRecordLabel->BackColor = System::Drawing::Color::Gray;
			this->saveRecordLabel->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->saveRecordLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->saveRecordLabel->Location = System::Drawing::Point(48, 0);
			this->saveRecordLabel->Name = L"saveRecordLabel";
			this->saveRecordLabel->Size = System::Drawing::Size(0, 18);
			this->saveRecordLabel->TabIndex = 14;
			// 
			// PlayVideoRadioButton
			// 
			this->PlayVideoRadioButton->AutoSize = true;
			this->PlayVideoRadioButton->Enabled = false;
			this->PlayVideoRadioButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->PlayVideoRadioButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->PlayVideoRadioButton->Location = System::Drawing::Point(553, 7);
			this->PlayVideoRadioButton->Name = L"PlayVideoRadioButton";
			this->PlayVideoRadioButton->Size = System::Drawing::Size(66, 23);
			this->PlayVideoRadioButton->TabIndex = 17;
			this->PlayVideoRadioButton->TabStop = true;
			this->PlayVideoRadioButton->Text = L"Video";
			this->PlayVideoRadioButton->UseVisualStyleBackColor = true;
			this->PlayVideoRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::PlayVideoRadioButton_CheckedChanged);
			// 
			// PlayCameraRadioButton
			// 
			this->PlayCameraRadioButton->AutoSize = true;
			this->PlayCameraRadioButton->Checked = true;
			this->PlayCameraRadioButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->PlayCameraRadioButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->PlayCameraRadioButton->Location = System::Drawing::Point(553, 40);
			this->PlayCameraRadioButton->Name = L"PlayCameraRadioButton";
			this->PlayCameraRadioButton->Size = System::Drawing::Size(78, 23);
			this->PlayCameraRadioButton->TabIndex = 18;
			this->PlayCameraRadioButton->TabStop = true;
			this->PlayCameraRadioButton->Text = L"Camera";
			this->PlayCameraRadioButton->UseVisualStyleBackColor = true;
			this->PlayCameraRadioButton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::PlayCameraRadioButton_CheckedChanged);
			// 
			// startRecordingButton
			// 
			this->startRecordingButton->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->startRecordingButton->Enabled = false;
			this->startRecordingButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->startRecordingButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->startRecordingButton->Location = System::Drawing::Point(631, 3);
			this->startRecordingButton->Name = L"startRecordingButton";
			this->startRecordingButton->Size = System::Drawing::Size(135, 63);
			this->startRecordingButton->TabIndex = 20;
			this->startRecordingButton->Text = L"Start recording";
			this->startRecordingButton->UseVisualStyleBackColor = false;
			this->startRecordingButton->Click += gcnew System::EventHandler(this, &MyForm::startRecordingButton_Click);
			// 
			// RecordVideoRadioButton
			// 
			this->RecordVideoRadioButton->AutoSize = true;
			this->RecordVideoRadioButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->RecordVideoRadioButton->Location = System::Drawing::Point(552, 3);
			this->RecordVideoRadioButton->Name = L"RecordVideoRadioButton";
			this->RecordVideoRadioButton->Size = System::Drawing::Size(60, 22);
			this->RecordVideoRadioButton->TabIndex = 21;
			this->RecordVideoRadioButton->Text = L"Video";
			this->RecordVideoRadioButton->UseVisualStyleBackColor = true;
			// 
			// RecordImagesRadioButton
			// 
			this->RecordImagesRadioButton->AutoSize = true;
			this->RecordImagesRadioButton->Checked = true;
			this->RecordImagesRadioButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->RecordImagesRadioButton->Location = System::Drawing::Point(552, 40);
			this->RecordImagesRadioButton->Name = L"RecordImagesRadioButton";
			this->RecordImagesRadioButton->Size = System::Drawing::Size(70, 22);
			this->RecordImagesRadioButton->TabIndex = 22;
			this->RecordImagesRadioButton->TabStop = true;
			this->RecordImagesRadioButton->Text = L"Images";
			this->RecordImagesRadioButton->UseVisualStyleBackColor = true;
			// 
			// framesCheckBox
			// 
			this->framesCheckBox->AutoSize = true;
			this->framesCheckBox->Location = System::Drawing::Point(531, 23);
			this->framesCheckBox->Name = L"framesCheckBox";
			this->framesCheckBox->Size = System::Drawing::Size(15, 14);
			this->framesCheckBox->TabIndex = 23;
			this->framesCheckBox->UseVisualStyleBackColor = true;
			this->framesCheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->imagePath);
			this->panel1->Controls->Add(this->imageToReplaceButton);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->saveRecordLabel);
			this->panel1->Controls->Add(this->startRecordingButton);
			this->panel1->Controls->Add(this->framesCheckBox);
			this->panel1->Controls->Add(this->RecordVideoRadioButton);
			this->panel1->Controls->Add(this->RecordImagesRadioButton);
			this->panel1->Controls->Add(this->selectDestinationButton);
			this->panel1->Controls->Add(this->framesTosaveText);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(80, 559);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(771, 71);
			this->panel1->TabIndex = 24;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(531, 3);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 30;
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Gray;
			this->label4->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F, System::Drawing::FontStyle::Bold));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(393, 1);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(125, 18);
			this->label4->TabIndex = 29;
			this->label4->Text = L"replace by image";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Gray;
			this->label5->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(201, 1);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 18);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Path:";
			// 
			// imagePath
			// 
			this->imagePath->AutoSize = true;
			this->imagePath->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->imagePath->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->imagePath->Location = System::Drawing::Point(235, 1);
			this->imagePath->Name = L"imagePath";
			this->imagePath->Size = System::Drawing::Size(0, 18);
			this->imagePath->TabIndex = 27;
			this->imagePath->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// imageToReplaceButton
			// 
			this->imageToReplaceButton->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->imageToReplaceButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->imageToReplaceButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->imageToReplaceButton->Location = System::Drawing::Point(204, 22);
			this->imageToReplaceButton->Name = L"imageToReplaceButton";
			this->imageToReplaceButton->Size = System::Drawing::Size(183, 44);
			this->imageToReplaceButton->TabIndex = 24;
			this->imageToReplaceButton->Text = L"Select image to replace";
			this->imageToReplaceButton->UseVisualStyleBackColor = false;
			this->imageToReplaceButton->Click += gcnew System::EventHandler(this, &MyForm::imageToReplaceButton_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Gray;
			this->label3->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(3, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 18);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Path:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Gray;
			this->panel2->Controls->Add(this->saveImageButton);
			this->panel2->Controls->Add(this->PlayVideoRadioButton);
			this->panel2->Controls->Add(this->PlayCameraRadioButton);
			this->panel2->Controls->Add(this->videoPath);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->cameraButton);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Location = System::Drawing::Point(80, 5);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(771, 66);
			this->panel2->TabIndex = 25;
			// 
			// saveImageButton
			// 
			this->saveImageButton->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->saveImageButton->Enabled = false;
			this->saveImageButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveImageButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->saveImageButton->Location = System::Drawing::Point(397, 3);
			this->saveImageButton->Name = L"saveImageButton";
			this->saveImageButton->Size = System::Drawing::Size(131, 60);
			this->saveImageButton->TabIndex = 26;
			this->saveImageButton->Text = L"Save image";
			this->saveImageButton->UseVisualStyleBackColor = false;
			this->saveImageButton->Click += gcnew System::EventHandler(this, &MyForm::saveImageButton_Click);
			// 
			// motionDetectorButton
			// 
			this->motionDetectorButton->BackColor = System::Drawing::SystemColors::Control;
			this->motionDetectorButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->motionDetectorButton->Font = (gcnew System::Drawing::Font(L"Noto Sans", 9.75F));
			this->motionDetectorButton->Location = System::Drawing::Point(857, 410);
			this->motionDetectorButton->Name = L"motionDetectorButton";
			this->motionDetectorButton->Size = System::Drawing::Size(67, 143);
			this->motionDetectorButton->TabIndex = 26;
			this->motionDetectorButton->Text = L"Motion detect";
			this->motionDetectorButton->UseVisualStyleBackColor = false;
			this->motionDetectorButton->Click += gcnew System::EventHandler(this, &MyForm::motionDetectorButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(929, 634);
			this->Controls->Add(this->motionDetectorButton);
			this->Controls->Add(this->CopyFaceButton);
			this->Controls->Add(this->PinkCircleButton);
			this->Controls->Add(this->BlackLineButton);
			this->Controls->Add(this->BlurButton);
			this->Controls->Add(this->imageWindow);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageWindow))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		OpenFileDialog^ dgOpen = gcnew OpenFileDialog();
		dgOpen->Filter = "All files(*.*)|*.*||";
		if (dgOpen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}
		System::String^ directoryPath = dgOpen->FileName;

		if (directoryPath->Length > 33) {
			videoPath->Text = "..." +  directoryPath->Substring(directoryPath->Length - 33, 33);
		}
		else {
			videoPath->Text = directoryPath;
		}

		videoPathStr = msclr::interop::marshal_as<std::string>(directoryPath);
		if (cameraButton->Text == L"Run camera") {
			PlayVideoRadioButton->Enabled = true;
		}
	}

	private: char* ConvertString2Char(System::String^ str) {
		char* str2 = (char*)(void*)Marshal::StringToHGlobalAnsi(str);
		return str2;
	}
			
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (!original.empty()) {
			frame2 = original.clone();
		}
		cap >> original;
		frame = original.clone();
		proccessImage();
	}

	private: void proccessImage(){
		if (!frame.empty()) {

			 if (dWidth != 0 && frame.cols != dWidth) {
				 resize(frame, frame, cv::Size(dWidth, dHeight));
			 }

		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
		equalizeHist(frame_gray, frame_gray);
		face_cascade.detectMultiScale(frame_gray, faces, 10, 3, 0 | CASCADE_SCALE_IMAGE, cv::Size(30, 30));
		
		Rect first_face_area;
		 Mat first_face;

		int size = faces.size();
		if (choice == 4 && size > 1) {
			 for (int i = 0; i < size - 1; i++) {
				double x_diff = mouseX - (faces[i].x + faces[i].width / 2);
				double y_diff = mouseY - (faces[i].y + faces[i].width / 2);
				int dist = std::sqrt(x_diff * x_diff + y_diff * y_diff);

				double x_diff1 = mouseX - (faces[i + 1].x + faces[i + 1].width / 2);
				double y_diff1 = mouseY - (faces[i + 1].y + faces[i + 1].width / 2);
				int dist2 = std::sqrt(x_diff1 * x_diff1 + y_diff1 * y_diff1);

				if (dist > dist2) {
						 Rect tmp = faces[i];
						 faces[i] = faces[i + 1];
						 faces[i + 1] = tmp;
				}
			 }
		size = 1;
		}

	
		for (int i = 0; i < size; i++) {
				Rect face_area = faces[i];
				Mat faceROI = frame_gray(faces[i]);
				std::vector<Rect> eyes;
				eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, cv::Size(30, 30));
				cv::Point left_side(face_area.x, face_area.y + face_area.height / 2);
				Rect eyes_area(left_side - cv::Point(0, face_area.height / 3), cv::Size(face_area.width, face_area.height / 3));
			switch (choice) {
			case 1: {
				cv::Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
				ellipse(frame, center, cv::Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360,
					Scalar(255, 0, 255), 4);
			}
				break;
			case 2:
				GaussianBlur(frame(face_area), frame(face_area), cv::Size(15, 15), 20);
				break;
			case 3:	
				rectangle(frame, eyes_area, Scalar(0, 0, 0), -1);
				break;
			case 4:
				if (faces.size() > 1) {
					for (int j = 0; j < faces.size(); j++) {
						if (imagePathStr != "" && useImage==true) {
							Mat imageFromPath = imread(imagePathStr, 1);
							frame2 = imageFromPath.clone();
						}
						else {
							frame2 = frame(face_area);
						}
						resize(frame2, frame2, cv::Size(faces[j].width, faces[j].height));
						Rect WhereRec(faces[j].x, faces[j].y, frame2.cols, frame2.rows);
						frame2.copyTo(frame(WhereRec));
					}
				}
				break;
			}
		}

		if (choice == 5) {
			if (delay > 0) {
				delay--;
			}
			if (!frame2.empty()) {
				auto now = std::chrono::system_clock::now();
				auto in_time_t = std::chrono::system_clock::to_time_t(now);
				std::stringstream ss;
				ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
				string aktualnyCzas = ss.str();
				putText(frame, aktualnyCzas, cv::Point2i(frame.cols - 190, frame.rows - 30), FONT_HERSHEY_PLAIN, 1, Scalar(240, 240, 240), 2);
				if (montionDetector(frame2, frame)) {
					delay = 24*5;
				}

				if (delay>0) {
					double max = 24 * 5;
					double multi = (double)delay / max;
					int color = (150 * multi) + 105;
					cout << color << endl;
					putText(frame, "Motion detected", cv::Point2i(30, frame.rows - 30), FONT_HERSHEY_PLAIN, 1, Scalar(0, 0, color), 2);
				}
				else {
					if (oVideoWriter.isOpened())
					switchRecordingButton();
				}
			}
		}


		if (startRecordingButton->Text == L"Stop recording" && imagesToRecord > 0) {
			if (!frame.empty()) {
				if (RecordImagesRadioButton->Checked == true) {
					imagesToRecord--;
					saveImage();
				}
				else {
					
					if (!oVideoWriter.isOpened()){
						auto now = std::chrono::system_clock::now();
						auto in_time_t = std::chrono::system_clock::to_time_t(now);
						std::stringstream ss;
						ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d-%H-%M-%S");
						string var = "\\video" + ss.str() + ".avi";
						string src = destinationPath + var;
						dWidth = frame.cols;
						dHeight = frame.rows;
						cv::Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));
						oVideoWriter.open(src, CV_FOURCC('M', 'J', 'P', 'G'), 20, frameSize, true);
					}
					imagesToRecord--;
					oVideoWriter.write(frame);
				}
			}
		}

		if (imagesToRecord == 0) {
			switchRecordingButton();
			if (framesTosaveText->Enabled == true) imagesToRecord = atoi(msclr::interop::marshal_as<std::string>(framesTosaveText->Text).c_str());
			else  imagesToRecord = 99999;
		}

		if (!frame.empty()) {
			imageWindow->Image = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr) frame.data);
			imageWindow->Refresh();
		}
	}
	else {
		cap.release();
		frame.release();
		imageWindow->Image = nullptr;
		switchCameraButton();
	}
	}

	bool montionDetector(Mat frame, Mat frame2) {
		Mat gray1, gray2;
		Mat diff, blurr_diff, thresh;
		cvtColor(frame, gray1, COLOR_BGR2GRAY);
		cvtColor(frame2, gray2, COLOR_BGR2GRAY);
		absdiff(gray1, gray2, diff);
		GaussianBlur(diff, blurr_diff, cv::Size(5, 5), 20);
		threshold(blurr_diff, thresh, 20, 255, THRESH_BINARY);
		vector<vector<cv::Point> > contours;
		findContours(thresh, contours, CV_RETR_EXTERNAL, CHAIN_APPROX_NONE);
		return contours.size() >= 25;
	}

	private: void saveImage(){
		vector<int> compression_params;
		compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
		compression_params.push_back(100);
		string src = destinationPath + "\\image" + to_string(imageIndex) + ".jpg";
		cout << imagesToRecord << endl;
		imwrite(src, frame);
		imageIndex++;
	}

	private: System::Void cameraButton_Click(System::Object^  sender, System::EventArgs^  e) {
		switchCameraButton();
	}

	private: void switchCameraButton() {
		if (cameraButton->Text == L"Run camera") {
			 PlayCameraRadioButton->Enabled = false;
			 PlayVideoRadioButton->Enabled = false;
			 if (!cap.isOpened()) cap.open(0);
			cameraButton->Text = L"Stop camera";
			 timer1->Start();
		} else if (cameraButton->Text == L"Stop camera") {
				 PlayCameraRadioButton->Enabled = true;
				 if (videoPath->Text != L"") {
					 PlayVideoRadioButton->Enabled = true;
				 }
				 cameraButton->Text = L"Run camera";
				 timer1->Stop();
			}
		if (cameraButton->Text == L"Run video") {
					 PlayCameraRadioButton->Enabled = false;
					 PlayVideoRadioButton->Enabled = false;
					 if (!cap.isOpened()) cap.open(videoPathStr);
					 cameraButton->Text = L"Stop video";
					 timer1->Start();

		}
		else if (cameraButton->Text == L"Stop video") {
		PlayCameraRadioButton->Enabled = true;
		if (videoPath->Text != L"") {
			 PlayVideoRadioButton->Enabled = true;
		}
		cameraButton->Text = L"Run video";
		timer1->Stop();
		}
	}

	private: System::Void Blur_Click(System::Object^  sender, System::EventArgs^  e) {
		resetColors();
		if (choice != 2) {
			choice = 2;
			BlurButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
		}
		else choice = 0;

		if (cap.isOpened()) {
			frame = original.clone();
			proccessImage();
		}
	}

	private: System::Void BlackLine_Click(System::Object^  sender, System::EventArgs^  e) {
		resetColors();
		if (choice != 3) {
			choice = 3;
			BlackLineButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
		}
		else choice = 0;

		if (cap.isOpened()) {
			frame = original.clone();
			proccessImage();
		}
	}

	private: System::Void PinkCircleButton_Click(System::Object^  sender, System::EventArgs^  e) {
		resetColors();
		if (choice != 1) {
			choice = 1;
			PinkCircleButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
		}
		else  choice = 0;

		if (cap.isOpened()) {
			frame = original.clone();
			proccessImage();
		}
	}

	private: System::Void CopyFaceButton_Click(System::Object^  sender, System::EventArgs^  e) {
		resetColors();
		if (choice != 4) {
			choice = 4;
			CopyFaceButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
		}
		else choice = 0;

		if (cap.isOpened()) {
			frame = original.clone();
			proccessImage();
		}
	}

	void resetColors(){
		 BlurButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
		 static_cast<System::Int32>(static_cast<System::Byte>(255)));
		 BlackLineButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
		 static_cast<System::Int32>(static_cast<System::Byte>(255)));
		 PinkCircleButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
		 static_cast<System::Int32>(static_cast<System::Byte>(255)));
		 CopyFaceButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
		 static_cast<System::Int32>(static_cast<System::Byte>(255)));
		 motionDetectorButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
			 static_cast<System::Int32>(static_cast<System::Byte>(255)));
	}

	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		imagesToRecord = atoi(msclr::interop::marshal_as<std::string>(framesTosaveText->Text).c_str());
	}

	private: System::Void selectDestinationButton_Click(System::Object^  sender, System::EventArgs^  e) {
		FolderBrowserDialog^ dgOpen = gcnew FolderBrowserDialog();
		if (dgOpen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}
		System::String^ directoryPath = dgOpen->SelectedPath;
		destinationPath = msclr::interop::marshal_as<std::string>(dgOpen->SelectedPath);
		destinationPath = ReplaceAll(destinationPath, std::string("\\"), std::string("\\\\"));
		cout << destinationPath << endl;

		if (directoryPath->Length > 18) {
			saveRecordLabel->Text = "..." + directoryPath->Substring(directoryPath->Length - 18, 18);
		}
		else {
			saveRecordLabel->Text = directoryPath;
		}

		startRecordingButton->Enabled = true;
		saveImageButton->Enabled = true;
	}

	private: string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			 str.replace(start_pos, from.length(), to);
			 start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
		}
		return str;
	}

	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (framesTosaveText->Enabled == false) {
			framesTosaveText->Enabled = true;
			imagesToRecord = atoi(msclr::interop::marshal_as<std::string>(framesTosaveText->Text).c_str());
		}
		else {
			framesTosaveText->Enabled = false;
			imagesToRecord = 999999;
		}
	}

	private: System::Void startRecordingButton_Click(System::Object^  sender, System::EventArgs^  e) {
		switchRecordingButton();
	}

	private: void switchRecordingButton(){

		if (startRecordingButton->Text == L"Start recording") {
			videoIndex++;
			startRecordingButton->Text = L"Stop recording";
			startRecordingButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(200)),
			static_cast<System::Int32>(static_cast<System::Byte>(200)));
			framesCheck = framesCheckBox->Enabled;
			framesTosave = framesTosaveText->Enabled;
			framesCheckBox->Enabled = false;
			framesTosaveText->Enabled = false;
			RecordVideoRadioButton->Enabled = false;
			RecordImagesRadioButton->Enabled = false;
		}else {
			startRecordingButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
			startRecordingButton->Text = L"Start recording";
			framesCheckBox->Enabled = framesCheck;
			framesTosaveText->Enabled = framesTosave;
			RecordVideoRadioButton->Enabled = true;
			RecordImagesRadioButton->Enabled = true;
			if (oVideoWriter.isOpened()) oVideoWriter.release();
		}
	}

	private: System::Void PlayVideoRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (cameraButton->Text == L"Run camera") {
			if (cap.isOpened()) {
				cap.release();
				frame.release();
				imageWindow->Image = nullptr;
			}
			cameraButton->Text = L"Run video";
		}
	}

	private: System::Void PlayCameraRadioButton_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (cameraButton->Text == L"Run video") {
			if (cap.isOpened()) {
				cap.release();
				frame.release();
				imageWindow->Image = nullptr;
			}
			cameraButton->Text = L"Run camera";
		}
	}

	private: System::Void saveImageButton_Click(System::Object^  sender, System::EventArgs^  e) {
		saveImage();
	}

	private: void  pb_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e){
		mouseX = e->X;
		mouseY = e->Y;
		frame = original.clone();
		proccessImage();
	}
	private: System::Void imageToReplaceButton_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ dgOpen = gcnew OpenFileDialog();
		dgOpen->Filter = "All files(*.*)|*.*||";
		if (dgOpen->ShowDialog() == System::Windows::Forms::DialogResult::Cancel) {
			return;
		}
		System::String^ directoryPath = dgOpen->FileName;

		if (directoryPath->Length > 18) {
			imagePath->Text = "..." +  directoryPath->Substring(directoryPath->Length - 18, 18);
		}
		else {
			imagePath->Text = directoryPath;
		}

		imagePathStr = msclr::interop::marshal_as<std::string>(directoryPath);
	}
private: System::Void checkBox1_CheckedChanged_1(System::Object^  sender, System::EventArgs^  e) {
	if (useImage == false) {
		useImage = true;
		frame = original.clone();
		proccessImage();
	}
	else {
		useImage = false;
		frame = original.clone();
		proccessImage();
	}
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void motionDetectorButton_Click(System::Object^  sender, System::EventArgs^  e) {
	resetColors();
	if (choice != 5) {
		choice = 5;
		motionDetectorButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
			static_cast<System::Int32>(static_cast<System::Byte>(128)));
	}
	else choice = 0;

	if (cap.isOpened()) {
		frame = original.clone();
		proccessImage();
	}
}
};
}

