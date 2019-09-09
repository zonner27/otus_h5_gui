#include <gtest/gtest.h>
#include "document.h"
#include "graphic_elements.h"

TEST(TestGUI, create_doc) {

    Document doc;
    Command *create = new NewDocumentCommand(&doc);
    create->execute();
    delete create;
}

TEST(TestGUI, import_doc) {

    Document doc;
    Command *import = new ImportDocumentCommand(&doc, "file.txt");
    import->execute();
    delete import;
}

TEST(TestGUI, export_doc) {

    Document doc;
    Command *exports = new ExportDocumentCommand(&doc, "file.txt");
    exports->execute();
    delete exports;
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
