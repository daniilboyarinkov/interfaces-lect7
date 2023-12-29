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

QVector<int> Form::boyerMooreSearch(const QString &text, const QString &pattern) {
    int n = text.length();
    int m = pattern.length();

    QVector<int> indexes;

    if (m == 0) {
        indexes.append(0); // Пустая подстрока всегда найдется
    }

    QVector<int> shift(256, m);
    for (int i = 0; i < m - 1; i++) {
        shift[pattern[i]] = m - 1 - i;
    }

    int i = m - 1; // Индекс для прохода по тексту
    int j = m - 1; // Индекс для прохода по подстроке
    do {
        if (text[i] == pattern[j]) {
            if (j == 0) {
                indexes.append(i); // Найдено полное совпадение
                i--;
                j = m - 1;
            } else {
                i--;
                j--;
            }
        } else {
            i += shift[text[i]] > m - j ? shift[text[i]] : m - j;
            j = m - 1;
        }
    } while (i < n);

    return indexes;
}

void Form::start() {
    QString str = ui->str->text();
    QString substr = ui->sub_str->text();

    QVector<int> indexes = boyerMooreSearch(str, substr);

    if (!indexes.isEmpty()) {
        QString result = "Indexes: ";
        for (int index : indexes) {
            result += QString::number(index) + " ";
        }
        ui->result->setText(result);
    } else {
        ui->result->setText("Substring not found");
    }
}

