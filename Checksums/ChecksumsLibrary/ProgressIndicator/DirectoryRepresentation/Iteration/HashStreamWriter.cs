using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator.DirectoryRepresentation.Iteration
{
    public class HashStreamWriter : AbstractFileSystemVisitor
    {
        private IChecksumClaculator calculator;
        private Stream writer;

        public HashStreamWriter(IChecksumClaculator calculator, Stream writer)
        {
            this.calculator = calculator;
            this.writer = writer;
        }

        public void changeCalculator(IChecksumClaculator newCalculator)
        {
            this.calculator = newCalculator;
        }

        public void calculate(Stream inputStream, string fileName)
        {
            byte[] str = Encoding.ASCII
                .GetBytes(this.calculator.calculate(inputStream) + " : " + fileName + Environment.NewLine);
            this.writer.Write(str,0,str.Length);
        }

        public override void visitDirectory(Directory directory)
        {
            foreach (var resource in directory.GetFilesAndDirs())
            {
                // TODO:: I know it is a bad idea, but do not see it other way!
                if(resource is File)
                {
                    visitFile((File)resource);
                }
                else
                {
                    visitDirectory((Directory)resource);
                }
            }
        }

        public override void visitFile(File file)
        {
            try
            {
                this.calculate(new FileStream(file.Path, FileMode.Open), file.Path);
            }
            catch (UnauthorizedAccessException ex)
            {
                this.writer.Write(Encoding.ASCII
                .GetBytes("Access to file denied!!!" + Environment.NewLine));
            }
        }
    }
}
