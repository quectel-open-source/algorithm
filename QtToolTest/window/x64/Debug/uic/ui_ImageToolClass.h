/********************************************************************************
** Form generated from reading UI file 'ImageToolClass.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGETOOLCLASS_H
#define UI_IMAGETOOLCLASS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageToolClassClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QFrame *frame_5;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_28;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QToolButton *toolButton_7;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_title;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_10;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_provious;
    QLabel *label_image;
    QToolButton *toolButton_next;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_imageNumber;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButton_switchImage;
    QPushButton *btn_openImage;
    QPushButton *btn_imagefiles;
    QPushButton *btn_deleteImage;
    QListWidget *listWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageToolClassClass)
    {
        if (ImageToolClassClass->objectName().isEmpty())
            ImageToolClassClass->setObjectName(QString::fromUtf8("ImageToolClassClass"));
        ImageToolClassClass->resize(1333, 876);
        centralWidget = new QWidget(ImageToolClassClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(2);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(2, 2, 2, 2);
        frame_5 = new QFrame(centralWidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setStyleSheet(QString::fromUtf8("background-color: rgb(12, 34, 56);"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_5);
        gridLayout_3->setSpacing(2);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame = new QFrame(frame_5);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(2);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_10 = new QLabel(frame);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMaximumSize(QSize(100, 30));
        label_10->setPixmap(QPixmap(QString::fromUtf8("../../../MatchTest/Resources/Quectel LOGO-20220215.png")));
        label_10->setScaledContents(true);

        horizontalLayout_17->addWidget(label_10);

        horizontalSpacer_6 = new QSpacerItem(638, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_6);

        horizontalLayout_17->setStretch(0, 1);
        horizontalLayout_17->setStretch(1, 10);

        horizontalLayout_18->addLayout(horizontalLayout_17);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(20);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        toolButton_4->setFont(font);
        toolButton_4->setLayoutDirection(Qt::LeftToRight);
        toolButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_4->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(frame);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        toolButton_5->setFont(font);
        toolButton_5->setLayoutDirection(Qt::LeftToRight);
        toolButton_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_5->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_5->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(frame);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Serif"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        toolButton_6->setFont(font1);
        toolButton_6->setLayoutDirection(Qt::LeftToRight);
        toolButton_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_6->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_6->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_6);

        toolButton_7 = new QToolButton(frame);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setFont(font1);
        toolButton_7->setLayoutDirection(Qt::LeftToRight);
        toolButton_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        toolButton_7->setToolButtonStyle(Qt::ToolButtonTextOnly);
        toolButton_7->setAutoRaise(true);

        horizontalLayout_28->addWidget(toolButton_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_28->addItem(horizontalSpacer);

        horizontalLayout_28->setStretch(0, 1);
        horizontalLayout_28->setStretch(1, 1);
        horizontalLayout_28->setStretch(2, 1);
        horizontalLayout_28->setStretch(3, 1);

        horizontalLayout_18->addLayout(horizontalLayout_28);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_3);

        label_title = new QLabel(frame);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        label_title->setFont(font2);

        horizontalLayout_18->addWidget(label_title);

        horizontalSpacer_7 = new QSpacerItem(678, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../MatchTest/Resources/\347\252\227\345\217\243\346\234\200\345\260\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../MatchTest/Resources/expand-\345\205\250\345\261\217\345\214\226.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\205\263\351\227\255.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon2);
        toolButton_3->setIconSize(QSize(25, 25));

        horizontalLayout_10->addWidget(toolButton_3);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 11);

        horizontalLayout_18->addLayout(horizontalLayout_10);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 2);
        horizontalLayout_18->setStretch(2, 10);
        horizontalLayout_18->setStretch(3, 8);
        horizontalLayout_18->setStretch(4, 20);
        horizontalLayout_18->setStretch(5, 1);

        gridLayout->addLayout(horizontalLayout_18, 0, 0, 1, 1);


        verticalLayout_3->addWidget(frame);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButton_provious = new QToolButton(frame_5);
        toolButton_provious->setObjectName(QString::fromUtf8("toolButton_provious"));
        sizePolicy.setHeightForWidth(toolButton_provious->sizePolicy().hasHeightForWidth());
        toolButton_provious->setSizePolicy(sizePolicy);
        toolButton_provious->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\210\207\346\215\242\345\231\250\345\267\246.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_provious->setIcon(icon3);
        toolButton_provious->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(toolButton_provious);

        label_image = new QLabel(frame_5);
        label_image->setObjectName(QString::fromUtf8("label_image"));
        label_image->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_image->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_image);

        toolButton_next = new QToolButton(frame_5);
        toolButton_next->setObjectName(QString::fromUtf8("toolButton_next"));
        sizePolicy.setHeightForWidth(toolButton_next->sizePolicy().hasHeightForWidth());
        toolButton_next->setSizePolicy(sizePolicy);
        toolButton_next->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\210\207\346\215\242\345\231\250\345\217\263.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_next->setIcon(icon4);
        toolButton_next->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(toolButton_next);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 15);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        tabWidget = new QTabWidget(frame_5);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(12);
        font3.setBold(false);
        font3.setWeight(50);
        tabWidget->setFont(font3);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(2);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(2, 2, 2, 2);
        frame_2 = new QFrame(tab);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(2);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(2, 2, 2, 2);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_imageNumber = new QLabel(frame_2);
        label_imageNumber->setObjectName(QString::fromUtf8("label_imageNumber"));
        label_imageNumber->setFont(font2);
        label_imageNumber->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout->addWidget(label_imageNumber);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        radioButton_switchImage = new QRadioButton(frame_2);
        radioButton_switchImage->setObjectName(QString::fromUtf8("radioButton_switchImage"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(11);
        font4.setBold(false);
        font4.setWeight(50);
        radioButton_switchImage->setFont(font4);
        radioButton_switchImage->setChecked(true);

        horizontalLayout->addWidget(radioButton_switchImage);

        btn_openImage = new QPushButton(frame_2);
        btn_openImage->setObjectName(QString::fromUtf8("btn_openImage"));
        btn_openImage->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(27, 46, 71);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\216\206\345\217\262\345\233\276\345\203\217.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_openImage->setIcon(icon5);
        btn_openImage->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_openImage);

        btn_imagefiles = new QPushButton(frame_2);
        btn_imagefiles->setObjectName(QString::fromUtf8("btn_imagefiles"));
        btn_imagefiles->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(27, 46, 71);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../MatchTest/Resources/\346\211\223\345\274\200.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_imagefiles->setIcon(icon6);
        btn_imagefiles->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_imagefiles);

        btn_deleteImage = new QPushButton(frame_2);
        btn_deleteImage->setObjectName(QString::fromUtf8("btn_deleteImage"));
        btn_deleteImage->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);\n"
"background-color: rgb(27, 46, 71);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../MatchTest/Resources/\345\210\240\351\231\244.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_deleteImage->setIcon(icon7);
        btn_deleteImage->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_deleteImage);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 8);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 1);

        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(frame_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        listWidget->setIconSize(QSize(210, 175));
        listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setMovement(QListView::Static);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setSpacing(8);
        listWidget->setViewMode(QListView::ListMode);

        verticalLayout->addWidget(listWidget);

        verticalLayout->setStretch(0, 1);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_5->addWidget(frame_2, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidget);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 20);

        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);


        gridLayout_4->addWidget(frame_5, 0, 0, 1, 1);

        ImageToolClassClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ImageToolClassClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImageToolClassClass->setStatusBar(statusBar);

        retranslateUi(ImageToolClassClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ImageToolClassClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageToolClassClass)
    {
        ImageToolClassClass->setWindowTitle(QApplication::translate("ImageToolClassClass", "ImageToolClass", nullptr));
        label_10->setText(QString());
        toolButton_4->setText(QApplication::translate("ImageToolClassClass", "\350\256\276\347\275\256", nullptr));
        toolButton_5->setText(QApplication::translate("ImageToolClassClass", "\346\227\245\345\277\227", nullptr));
        toolButton_6->setText(QApplication::translate("ImageToolClassClass", "\350\257\255\350\250\200", nullptr));
        toolButton_7->setText(QApplication::translate("ImageToolClassClass", "\345\270\256\345\212\251", nullptr));
        label_title->setText(QApplication::translate("ImageToolClassClass", "TextLabel", nullptr));
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        toolButton_3->setText(QString());
        toolButton_provious->setText(QString());
        label_image->setText(QString());
        toolButton_next->setText(QString());
        label_imageNumber->setText(QApplication::translate("ImageToolClassClass", "\345\233\276\345\203\217\346\272\220(0/0)", nullptr));
        radioButton_switchImage->setText(QApplication::translate("ImageToolClassClass", "\350\207\252\345\212\250\345\210\207\346\215\242", nullptr));
        btn_openImage->setText(QString());
        btn_imagefiles->setText(QString());
        btn_deleteImage->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ImageToolClassClass", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageToolClassClass: public Ui_ImageToolClassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGETOOLCLASS_H
