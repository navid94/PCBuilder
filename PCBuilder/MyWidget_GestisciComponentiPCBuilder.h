#ifndef MYWIDGET_GESTISCICOMPONENTIPCBUILDER_H
#define MYWIDGET_GESTISCICOMPONENTIPCBUILDER_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QString>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QStackedWidget>
#include <QCheckBox>
#include <QLayout>

#include "AlimentatoreAddWidget.h"
#include "AltoparlantiAddWidget.h"
#include "ArchiviazioneAddWidget.h"
#include "CaseAddWidget.h"
#include "CuffieAddWidget.h"
#include "DissipatoreProcessoreAddWidget.h"
#include "MemoriaAddWidget.h"
#include "MonitorAddWidget.h"
#include "MouseAddWidget.h"
#include "ProcessoreAddWidget.h"
#include "SchedaGraficaAddWidget.h"
#include "SchedaMadreAddWidget.h"
#include "SistemaOperativoAddWidget.h"
#include "TastieraAddWidget.h"
#include "UnitaOtticaAddWidget.h"

class MyWidget_GestisciComponentiPCBuilder:public QWidget{
    Q_OBJECT
private:
    QLabel* PCBuilder_Gestione_componentiLabel;
    QLabel* aggiungi_componenteLabel;
    QLabel* rimuovi_componenteLabel;

    QHBoxLayout* horizontalLayout3;

    QLineEdit* rimuoviComponenteLineEdit;

    QPushButton* indietroPushButton;
    QPushButton* aggiungiPushButton;
    QPushButton* rimuoviPushButton;

    QComboBox* tipo_componenteAggiungi;

    void createLabels();
    void createPushButtons();
    void createLineEdits();
    void createComboBoxes();
public:
    MyWidget_GestisciComponentiPCBuilder(QWidget* =0);
    void clearForms();

    QPushButton* get_indietroPushButton() const;
    QPushButton* get_aggiungi_PushButton() const;
    QPushButton* get_rimuoviPushButton() const;

    QString tipo_componenteAggiungiValue() const;

    QString rimuoviComponenteValue() const;

    QLineEdit* getRimuoviComponenteLineEdit() const;

    QComboBox* getTipo_componenteAggiungi() const;

    QHBoxLayout* getHorizontalLayout3() const;
};

#endif // MYWIDGET_GESTISCICOMPONENTIPCBUILDER_H
