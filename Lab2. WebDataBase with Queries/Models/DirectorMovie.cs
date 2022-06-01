using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

namespace MovieBase
{
    public partial class DirectorMovie
    {
        public int Id { get; set; }
        [Display(Name = "Режисер")]
        public int DirectorId { get; set; }
        [Display(Name = "Фільм")]
        public int MovieId { get; set; }

        [Display(Name = "Режисер")]
        public virtual Director? Director { get; set; } = null!;
        [Display(Name = "Фільм")]
        public virtual Movie? Movie { get; set; } = null!;
    }
}
