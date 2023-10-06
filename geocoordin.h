#ifndef GEOCOORDIN_H
#define GEOCOORDIN_H

#include <QLineEdit>
#include <QRegularExpressionValidator>

class GeoCoordin : public QLineEdit
{
    Q_OBJECT
public:
    explicit GeoCoordin(bool longitude, QWidget *parent = nullptr) : QLineEdit{parent}
    {
        if(longitude){
            setInputMask("099*09'09.000''");
             previousProperText_ = "000*00'00.000''";
        }
        else {
            setInputMask("99*09'00.000''");
             previousProperText_ = "00*00'00.000''";
            regex_ = "([9][0]\\*[0][0]'[0][0]\\.[0][0][0]'')|([0-8][0-9]\\*[0-5][0-9]'[0-5][0-9]\\.[0-9]{3}'')";
        }

        rx_.setPattern(regex_);
        setText(previousProperText_);

        connect(this, &QLineEdit::textEdited, this, &GeoCoordin::onTextChanged);
    }

private slots:
    void onTextChanged(const QString &text)
    {
        if(previousProperText_.size() != text.size())
            setText(previousProperText_);

        int curPos = cursorPosition();

        QRegularExpressionMatch match = rx_.match(text);

        if(match.hasMatch())
        {
            previousProperText_ = text;
        }
        else
        {
            setText(previousProperText_);
        }

        setCursorPosition(curPos);
    }

private:
    QRegularExpression rx_;
    QString regex_ = "([1][8][0]\\*[0][0]'[0][0]\\.[0][0][0]'')|(([0][0-9]{2}|[1][0-7][0-9])\\*[0-5][0-9]'[0-5][0-9]\\.[0-9]{3}'')";
    QString previousProperText_;
};

#endif // GEOCOORDIN_H
