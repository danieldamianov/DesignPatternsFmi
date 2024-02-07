using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ChecksumsLibrary.ProgressIndicator
{
    public interface ProcessedFileObserver
    {
        void handleProcessedFile(string name, long bytesProcessed);
    }
}
