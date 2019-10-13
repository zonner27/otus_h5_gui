#include <gtest/gtest.h>
#include "document.h"
#include "graphic_elements.h"


TEST(TestGUI, create_doc) {

    std::unique_ptr<Document> doc;
    std::unique_ptr<Command> create_doc(new NewDocumentCommand(doc.get()));
    testing::internal::CaptureStdout();
    create_doc->execute();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output == "Create new document\n");
}

TEST(TestGUI, import_doc) {

    std::unique_ptr<Document> doc;
    std::unique_ptr<Command> import(new ImportDocumentCommand(doc.get(), "file.txt"));
    testing::internal::CaptureStdout();
    import->execute();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output == "Import document file.txt\n");
}

TEST(TestGUI, export_doc) {

    std::unique_ptr<Document> doc;
    std::unique_ptr<Command> exports(new ExportDocumentCommand(doc.get(), "file.txt"));
    testing::internal::CaptureStdout();
    exports->execute();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(output == "Export document file.txt\n");
}

int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
