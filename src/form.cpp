#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

int boyerMooreSearch(const QString &text, const QString &pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m == 0) {
        return 0; // Пустая подстрока всегда найдется
    }

    // Предподсчет смещений для символов в подстроке
    QVector<int> shift(256, m);
    for (int i = 0; i < m - 1; i++) {
        shift[pattern[i].toLatin1()] = m - 1 - i;
    }

    int i = m - 1; // Индекс для прохода по тексту
    int j = m - 1; // Индекс для прохода по подстроке
    do {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                return i; // Найдено полное совпадение
            }
            i--;
            j--;
        } else {
            i += shift[text[i].toLatin1()] > m - j ? shift[text[i].toLatin1()] : m - j;
            j = m - 1;
        }
    } while (i < n);

    return -1; // Подстрока не найдена
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();

    int index = boyerMooreSearch(str, sub_str);
:
    if (index != -1) {
        ui->result->setText("yes");
    } else {
        ui->result->setText("no");
    }
}

