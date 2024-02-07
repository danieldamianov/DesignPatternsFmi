using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Iteration
{
    public class ReportWriter : AbstractFileSystemVisitor
    {
        public ReportWriter(Stream writer) : base(writer)
        {
        }

        public override void visitDirectory(Directory directory)
        {
            writer.Write(Encoding.ASCII.GetBytes("Directry : " + directory.Path + " : length : " + directory.GetSizeInBytes()
                + Environment.NewLine));

            traverseDirectory(directory);
        }

        public override void visitFile(File file)
        {
            writer.Write(Encoding.ASCII.GetBytes("File : " + file.Path + " : length : " + file.GetSizeInBytes()
                + Environment.NewLine));
        }
    }
}
