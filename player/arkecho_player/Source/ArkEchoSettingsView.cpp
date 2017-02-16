#include "ArkEchoSettingsView.h"
#include "ArkEchoSettingsModel.h"

const QString DIALOGTITLE = "Einstellungen";

enum SWSETTINGSPAGEINDEX
{
    DIRECTORIES = 0,
    TEST = 1
};

ArkEchoSettingsView::ArkEchoSettingsView(QWidget *parent)
    : QDialog(parent)
    ,ui_(0)
    ,model_(0)
{
    ui_ = new Ui::ArkEchoSettingsView();
    ui_->setupUi(this);
    connect(ui_->lwSettings, SIGNAL(itemPressed(QListWidgetItem*)), this, SLOT(onLwSettingsItemPressed(QListWidgetItem*)));
    connect(ui_->pbDirectoryNew, SIGNAL(clicked()), this, SLOT(onPbDirectoryNewClicked()));
    connect(ui_->pbDirectoryEdit, SIGNAL(clicked()), this, SLOT(onPbDirectoryEditClicked()));
    connect(ui_->pbDirectoryDelete, SIGNAL(clicked()), this, SLOT(onPbDirectoryDeleteClicked()));

    model_ = new ArkEchoSettingsModel();

    initUi();
}

ArkEchoSettingsView::~ArkEchoSettingsView()
{
    delete model_;
    delete ui_;
}

void ArkEchoSettingsView::onPbDirectoryNewClicked()
{
    if (!model_) return;
    model_->newDirectory();
    setLwDirectories();
}

void ArkEchoSettingsView::onPbDirectoryEditClicked()
{
    if (!model_ || !ui_) return;

    // Get selected Item (Single Selection Mode; only One)
    QListWidgetItem* item = ui_->lwDirectories->selectedItems().at(0);
    if (!item) return;
    int index = item->type();
    model_->editDirectory(index);
    setLwDirectories();
}

void ArkEchoSettingsView::onPbDirectoryDeleteClicked()
{
    if (!model_ || !ui_) return;

    // Get selected Item (Single Selection Mode; only One)
    QListWidgetItem* item = ui_->lwDirectories->selectedItems().at(0);
    if (!item) return;
    int index = item->type();
    model_->deleteDirectory(index);
    setLwDirectories();
}

void ArkEchoSettingsView::initUi()
{
    this->setWindowTitle(DIALOGTITLE);

    // ListWidget Settings initilisieren
    QListWidgetItem* item0 = new QListWidgetItem("Dateipfade anpassen", ui_->lwSettings, SWSETTINGSPAGEINDEX::DIRECTORIES);
    QListWidgetItem* item1 = new QListWidgetItem("Test", ui_->lwSettings, SWSETTINGSPAGEINDEX::TEST);

    // Set selected Page & Item
    ui_->lwSettings->setItemSelected(item0, true);
    ui_->swSettings->setCurrentIndex(0);

    // Path Page
    setLwDirectories();
}

void ArkEchoSettingsView::setSwSettingsPageIndex(int index)
{
    ui_->swSettings->setCurrentIndex(index);
}

void ArkEchoSettingsView::setLwDirectories()
{
    if (!model_ || !ui_) return;
    ui_->lwDirectories->clear();
    QStringList directories = model_->getDirectoriesList();
    for (int i = 0; i < directories.size(); ++i)
    {
        QListWidgetItem* item = new QListWidgetItem(directories.at(i), ui_->lwDirectories, i);
    }
}

void ArkEchoSettingsView::onLwSettingsItemPressed(QListWidgetItem* item)
{
    if (!item) return;
    setSwSettingsPageIndex(item->type());
}