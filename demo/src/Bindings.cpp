/* generated by rust_qt_binding_generator */
#include "Bindings.h"

namespace {
    struct qbytearray_t {
    private:
        const char* data;
        int len;
    public:
        qbytearray_t(const QByteArray& v):
            data(v.data()),
            len(v.size()) {
        }
        operator QByteArray() const {
            return QByteArray(data, len);
        }
    };
    struct qstring_t {
    private:
        const void* data;
        int len;
    public:
        qstring_t(const QString& v):
            data(static_cast<const void*>(v.utf16())),
            len(v.size()) {
        }
        operator QString() const {
            return QString::fromUtf8(static_cast<const char*>(data), len);
        }
    };
    struct qmodelindex_t {
        int row;
        quintptr id;
    };
}
typedef void (*qstring_set)(QString*, qstring_t*);
void set_qstring(QString* v, qstring_t* val) {
    *v = *val;
}
typedef void (*qbytearray_set)(QByteArray*, qbytearray_t*);
void set_qbytearray(QByteArray* v, qbytearray_t* val) {
    *v = *val;
}

extern "C" {
    PersonInterface* person_new(Person*, void (*)(Person*), void (*)(Person*), void (*)(Person*), void (*)(Person*));
    void person_free(PersonInterface*);
    void person_user_name_get(PersonInterface*, QString*, qstring_set);
    void person_user_name_set(void*, qstring_t);
    int person_age_get(PersonInterface*);
    bool person_active_get(PersonInterface*);
    void person_active_set(void*, bool);
    void person_icon_get(PersonInterface*, QByteArray*, qbytearray_set);
    void person_icon_set(void*, qbytearray_t);
    DirectoryInterface* directory_new(Directory*, void (*)(Directory*),
        void (*)(const Directory*),
        void (*)(Directory*),
        void (*)(Directory*),
        void (*)(Directory*, int, int),
        void (*)(Directory*),
        void (*)(Directory*, int, int),
        void (*)(Directory*));
    void directory_free(DirectoryInterface*);
    void directory_path_get(DirectoryInterface*, QString*, qstring_set);
    void directory_path_set(void*, qstring_t);
    TestTreeInterface* test_tree_new(TestTree*, void (*)(TestTree*),
        void (*)(const TestTree*, int, quintptr),
        void (*)(TestTree*),
        void (*)(TestTree*),
        void (*)(TestTree*, int, quintptr, int, int),
        void (*)(TestTree*),
        void (*)(TestTree*, int, quintptr, int, int),
        void (*)(TestTree*));
    void test_tree_free(TestTreeInterface*);
    void test_tree_path_get(TestTreeInterface*, QString*, qstring_set);
    void test_tree_path_set(void*, qstring_t);
};
Person::Person(QObject *parent):
    QObject(parent),
    d(person_new(this,
        [](Person* o) { emit o->userNameChanged(); },
        [](Person* o) { emit o->ageChanged(); },
        [](Person* o) { emit o->activeChanged(); },
        [](Person* o) { emit o->iconChanged(); })) {}

Person::~Person() {
    person_free(d);
}
QString Person::userName() const
{
    QString v;
    person_user_name_get(d, &v, set_qstring);
    return v;
}
void Person::setUserName(const QString& v) {
    person_user_name_set(d, v);
}
int Person::age() const
{
    return person_age_get(d);
}
bool Person::active() const
{
    return person_active_get(d);
}
void Person::setActive(bool v) {
    person_active_set(d, v);
}
QByteArray Person::icon() const
{
    QByteArray v;
    person_icon_get(d, &v, set_qbytearray);
    return v;
}
void Person::setIcon(const QByteArray& v) {
    person_icon_set(d, v);
}
Directory::Directory(QObject *parent):
    QAbstractItemModel(parent),
    d(directory_new(this,
        [](Directory* o) { emit o->pathChanged(); },
        [](const Directory* o) {
            emit o->newDataReady(QModelIndex());
        },
        [](Directory* o) {
            o->beginResetModel();
        },
        [](Directory* o) {
            o->endResetModel();
        },
        [](Directory* o, int first, int last) {
            o->beginInsertRows(QModelIndex(), first, last);
        },
        [](Directory* o) {
            o->endInsertRows();
        },
        [](Directory* o, int first, int last) {
            o->beginRemoveRows(QModelIndex(), first, last);
        },
        [](Directory* o) {
            o->endRemoveRows();
        }
    )) {
    connect(this, &Directory::newDataReady, this, [this](const QModelIndex& i) {
        fetchMore(i);
    }, Qt::QueuedConnection);
}


Directory::~Directory() {
    directory_free(d);
}
QString Directory::path() const
{
    QString v;
    directory_path_get(d, &v, set_qstring);
    return v;
}
void Directory::setPath(const QString& v) {
    directory_path_set(d, v);
}
extern "C" {
    void directory_data_file_name(const DirectoryInterface*, int, QString*, qstring_set);
    void directory_data_file_icon(const DirectoryInterface*, int, QByteArray*, qbytearray_set);
    void directory_data_file_path(const DirectoryInterface*, int, QString*, qstring_set);
    int directory_data_file_permissions(const DirectoryInterface*, int);

    int directory_row_count(const DirectoryInterface*);
    bool directory_can_fetch_more(const DirectoryInterface*);
    void directory_fetch_more(DirectoryInterface*);
}
int Directory::columnCount(const QModelIndex &parent) const
{
    return (parent.isValid()) ? 0 : 3;
}

bool Directory::hasChildren(const QModelIndex &parent) const
{
    return rowCount(parent) > 0;
}

int Directory::rowCount(const QModelIndex &parent) const
{
    return (parent.isValid()) ? 0 : directory_row_count(d);
}

QModelIndex Directory::index(int row, int column, const QModelIndex &parent) const
{
    if (!parent.isValid() && column == 0) {
        return createIndex(row, 0, (quintptr)0);
    }
    return QModelIndex();
}

QModelIndex Directory::parent(const QModelIndex &) const
{
    return QModelIndex();
}

bool Directory::canFetchMore(const QModelIndex &parent) const
{
    return (parent.isValid()) ? 0 : directory_can_fetch_more(d);
}

void Directory::fetchMore(const QModelIndex &parent)
{
    if (!parent.isValid()) {
        directory_fetch_more(d);
    }
}

QVariant Directory::data(const QModelIndex &index, int role) const
{
    QVariant v;
    QString s;
    QByteArray b;
    switch (index.column()) {
    case 0:
        switch (role) {
        case Qt::DisplayRole:
            directory_data_file_name(d, index.row(), &s, set_qstring);
            v.setValue<QString>(s);
            break;
        case Qt::DecorationRole:
            directory_data_file_icon(d, index.row(), &b, set_qbytearray);
            v.setValue<QByteArray>(b);
            break;
        case Qt::UserRole + 1:
            directory_data_file_path(d, index.row(), &s, set_qstring);
            v.setValue<QString>(s);
            break;
        case Qt::UserRole + 2:
            directory_data_file_name(d, index.row(), &s, set_qstring);
            v.setValue<QString>(s);
            break;
        case Qt::UserRole + 3:
            v.setValue<int>(directory_data_file_permissions(d, index.row()));
            break;
        }
        break;
    case 1:
        switch (role) {
        case Qt::DisplayRole:
            directory_data_file_path(d, index.row(), &s, set_qstring);
            v.setValue<QString>(s);
            break;
        }
        break;
    case 2:
        switch (role) {
        case Qt::DisplayRole:
            v.setValue<int>(directory_data_file_permissions(d, index.row()));
            break;
        }
        break;
    }
    return v;
}
QHash<int, QByteArray> Directory::roleNames() const {
    QHash<int, QByteArray> names;
    names.insert(Qt::DisplayRole, "fileName");
    names.insert(Qt::DecorationRole, "fileIcon");
    names.insert(Qt::UserRole + 1, "filePath");
    names.insert(Qt::UserRole + 3, "filePermissions");
    return names;
}

TestTree::TestTree(QObject *parent):
    QAbstractItemModel(parent),
    d(test_tree_new(this,
        [](TestTree* o) { emit o->pathChanged(); },
        [](const TestTree* o, int row, quintptr id) {
            emit o->newDataReady(o->createIndex(row, 0, id));
        },
        [](TestTree* o) {
            o->beginResetModel();
        },
        [](TestTree* o) {
            o->endResetModel();
        },
        [](TestTree* o, int row, quintptr id, int first, int last) {
            o->beginInsertRows(o->createIndex(row, 0, id), first, last);
        },
        [](TestTree* o) {
            o->endInsertRows();
        },
        [](TestTree* o, int row, quintptr id, int first, int last) {
            o->beginRemoveRows(o->createIndex(row, 0, id), first, last);
        },
        [](TestTree* o) {
            o->endRemoveRows();
        }
    )) {
    connect(this, &TestTree::newDataReady, this, [this](const QModelIndex& i) {
        fetchMore(i);
    }, Qt::QueuedConnection);
}


TestTree::~TestTree() {
    test_tree_free(d);
}
QString TestTree::path() const
{
    QString v;
    test_tree_path_get(d, &v, set_qstring);
    return v;
}
void TestTree::setPath(const QString& v) {
    test_tree_path_set(d, v);
}
extern "C" {
    void test_tree_data_file_name(const TestTreeInterface*, int, quintptr, QString*, qstring_set);
    void test_tree_data_file_icon(const TestTreeInterface*, int, quintptr, QByteArray*, qbytearray_set);
    void test_tree_data_file_path(const TestTreeInterface*, int, quintptr, QString*, qstring_set);
    int test_tree_data_file_permissions(const TestTreeInterface*, int, quintptr);

    int test_tree_row_count(const TestTreeInterface*, int, quintptr);
    bool test_tree_can_fetch_more(const TestTreeInterface*, int, quintptr);
    void test_tree_fetch_more(TestTreeInterface*, int, quintptr);
    quintptr test_tree_index(const TestTreeInterface*, int, quintptr);
    qmodelindex_t test_tree_parent(const TestTreeInterface*, quintptr);
}
int TestTree::columnCount(const QModelIndex &) const
{
    return 3;
}

bool TestTree::hasChildren(const QModelIndex &parent) const
{
    return rowCount(parent) > 0;
}

int TestTree::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0) {
        return 0;
    }
    return test_tree_row_count(d, parent.row(), parent.internalId());
}

QModelIndex TestTree::index(int row, int column, const QModelIndex &parent) const
{
    if (row < 0 || column < 0 || column >= 3) {
        return QModelIndex();
    }
    if (parent.isValid() && parent.column() != 0) {
        return QModelIndex();
    }
    const quintptr id = test_tree_index(d, parent.row(), parent.internalId());
    return createIndex(row, column, id);
}

QModelIndex TestTree::parent(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return QModelIndex();
    }
    const qmodelindex_t parent = test_tree_parent(d, index.internalId());
    return parent.id ?createIndex(parent.row, 0, parent.id) :QModelIndex();
}

bool TestTree::canFetchMore(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0) {
        return false;
    }
    return test_tree_can_fetch_more(d, parent.row(), parent.internalId());
}

void TestTree::fetchMore(const QModelIndex &parent)
{
    test_tree_fetch_more(d, parent.row(), parent.internalId());
}

QVariant TestTree::data(const QModelIndex &index, int role) const
{
    QVariant v;
    QString s;
    QByteArray b;
    switch (index.column()) {
    case 0:
        switch (role) {
        case Qt::DisplayRole:
            test_tree_data_file_name(d, index.row(), index.internalId(), &s, set_qstring);
            v.setValue<QString>(s);
            break;
        case Qt::DecorationRole:
            test_tree_data_file_icon(d, index.row(), index.internalId(), &b, set_qbytearray);
            v.setValue<QByteArray>(b);
            break;
        case Qt::UserRole + 1:
            test_tree_data_file_path(d, index.row(), index.internalId(), &s, set_qstring);
            v.setValue<QString>(s);
            break;
        case Qt::UserRole + 2:
            test_tree_data_file_name(d, index.row(), index.internalId(), &s, set_qstring);
            v.setValue<QString>(s);
            break;
        case Qt::UserRole + 3:
            v.setValue<int>(test_tree_data_file_permissions(d, index.row(), index.internalId()));
            break;
        }
        break;
    case 1:
        switch (role) {
        case Qt::DisplayRole:
            test_tree_data_file_path(d, index.row(), index.internalId(), &s, set_qstring);
            v.setValue<QString>(s);
            break;
        }
        break;
    case 2:
        switch (role) {
        case Qt::DisplayRole:
            v.setValue<int>(test_tree_data_file_permissions(d, index.row(), index.internalId()));
            break;
        }
        break;
    }
    return v;
}
QHash<int, QByteArray> TestTree::roleNames() const {
    QHash<int, QByteArray> names;
    names.insert(Qt::DisplayRole, "fileName");
    names.insert(Qt::DecorationRole, "fileIcon");
    names.insert(Qt::UserRole + 1, "filePath");
    names.insert(Qt::UserRole + 3, "filePermissions");
    return names;
}
