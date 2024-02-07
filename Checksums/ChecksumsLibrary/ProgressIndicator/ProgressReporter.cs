using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator
{
    public class ProgressReporter : ProcessedFileObserver
    {
        public void handleProcessedFile(string name, long bytesProcessed)
        {
            // message born in HashStreamWriter
            if (bytesProcessed == -1)
            {
                Console.WriteLine("Now observing file : " + name);
            }
            else // message born in the checksum classes
            {
                Console.WriteLine("Processed: " + bytesProcessed + " from the file: " + name);
            }
        }
    }
}
