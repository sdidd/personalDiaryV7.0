#ifndef QFILESYSTEMMODELDIALOG_H
#define QFILESYSTEMMODELDIALOG_H

#include <QDialog>
#include <QFileSystemModel>

namespace Ui {
class QFileSystemModelDialog;
}

class QFileSystemModelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit QFileSystemModelDialog(QWidget *parent = 0);
    ~QFileSystemModelDialog();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::QFileSystemModelDialog *ui;

    // Make two models instead of one
    // to filter them separately
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
};

#endif // QFILESYSTEMMODELDIALOG_H
